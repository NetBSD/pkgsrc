# $NetBSD: do-cross.mk,v 1.6 2023/01/23 18:49:03 he Exp $
# Do all the NetBSD cross builds
# Collect the bootstrap kits in dist/

VERSION!=	make show-var VARNAME=PKGVERSION
V_NOREV!=	make show-var VARNAME=PKGVERSION_NOREV

SHORT_TARGETS+=		armv7
SHORT_TARGETS+=		armv6
SHORT_TARGETS+=		sparc64
SHORT_TARGETS+=		powerpc
SHORT_TARGETS+=		powerpc90
SHORT_TARGETS+=		arm64
SHORT_TARGETS+=		arm64_be
SHORT_TARGETS+=		i386
SHORT_TARGETS+=		mipsel	# produces mips32 (not mips1) executables

# Conditional local overrides of ROOT.* variables:
.sinclude "local-roots.mk"

# Root of target directories.
# Must have dest/ (build.sh's DESTDIR) and tools/ subdirectories
ROOT.armv7?=		/u/evbarm-armv7hf
ROOT.armv6?=		/u/evbarm-armv6hf
ROOT.sparc64?=		/u/sparc64
ROOT.powerpc?=		/u/macppc
ROOT.powerpc90?=	/u/9.0-macppc
ROOT.arm64?=		/u/evbarm64
ROOT.arm64_be?=		/u/evbarm64eb
ROOT.i386?=		/u/i386
ROOT.mipsel?=		/u/mipsel

# Mapping to GNU triple
G_TGT.armv7=		armv7--netbsdelf-eabihf
G_TGT.armv6=		armv6--netbsdelf-eabihf
G_TGT.sparc64=		sparc64--netbsd
G_TGT.powerpc=		powerpc--netbsd
G_TGT.powerpc90=	powerpc--netbsd
G_TGT.arm64=		aarch64--netbsd
G_TGT.arm64_be=		aarch64_be--netbsd
G_TGT.i386=		i486--netbsdelf
G_TGT.mipsel=		mipsel--netbsd

# Mapping to rust's TARGET specification
TGT.armv7=		armv7-unknown-netbsd-eabihf
TGT.armv6=		armv6-unknown-netbsd-eabihf
TGT.sparc64=		sparc64-unknown-netbsd
TGT.powerpc=		powerpc-unknown-netbsd
TGT.powerpc90=		powerpc-unknown-netbsd
TGT.arm64=		aarch64-unknown-netbsd
TGT.arm64_be=		aarch64_be-unknown-netbsd
TGT.i386=		i586-unknown-netbsd
TGT.mipsel=		mipsel-unknown-netbsd

# Optional target tweak for bootstrap files
TT.powerpc90=		powerpc-unknown-netbsd90

WRKDIR=		${.CURDIR}/work
SCRIPTS=	${WRKDIR}/scripts

#DEBUG=		echo

# Make list of make targets
.for st in ${SHORT_TARGETS}
MTGTS+=	do-${st}
.endfor

all: ${MTGTS}

# Define the individual build targets, used above
.for st in ${SHORT_TARGETS}
CA.${st}=--host=${TGT.${st}}
CA.${st}+=--target=${TGT.${st}}
CA.${st}+=--set=target.${TGT.${st}}.cc=${SCRIPTS}/gcc-wrap
CA.${st}+=--set=target.${TGT.${st}}.cxx=${SCRIPTS}/c++-wrap
CA.${st}+=--set=target.${TGT.${st}}.linker=${SCRIPTS}/gcc-wrap
CA.${st}+=--set=target.${TGT.${st}}.ar=${ROOT.${st}}/tools/bin/${G_TGT.${st}}-ar
do-${st}:
	mkdir -p dist
	@echo "=======> Cross-building rust for ${st}"
	${DEBUG} make -f Makefile clean
	${DEBUG} env \
		CROSS_ROOT=${ROOT.${st}} \
		GNU_CROSS_TARGET=${G_TGT.${st}} \
		make -f Makefile \
			ADD_CONFIGURE_ARGS="${CA.${st}}" \
			TARGET=${TGT.${st}}
	if [ "${TT.${st}}" != "" ]; then \
		TT=${TT.${st}}; \
	else \
		TT=${TGT.${st}}; \
	fi; \
	distdir=${WRKDIR}/rustc-${V_NOREV}-src/build/dist; \
	for comp in rust rust-std; do \
		src=$${distdir}/$${comp}-${V_NOREV}-${TGT.${st}}.tar.xz; \
		tgt=dist/$${comp}-${VERSION}-$${TT}.tar.xz; \
		if [ ! -f "$${tgt}" ]; then \
			echo ln $${src} $${tgt}; \
			${DEBUG} ln $${src} $${tgt}; \
		fi; \
	done; \
	src_comp=rust-src-${V_NOREV}.tar.xz; \
	if [ ! -f dist/$${src_comp} ]; then \
		echo ln $${distdir}/$${src_comp} dist; \
		${DEBUG} ln $${distdir}/$${src_comp} dist; \
	fi
.endfor
