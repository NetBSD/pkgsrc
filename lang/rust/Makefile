# $NetBSD: Makefile,v 1.206 2020/11/14 18:16:16 he Exp $

DISTNAME=	rustc-1.47.0-src
PKGNAME=	${DISTNAME:S/rustc/rust/:S/-src//}
CATEGORIES=	lang
MASTER_SITES=	https://static.rust-lang.org/dist/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.rust-lang.org/
COMMENT=	Safe, concurrent, practical language
LICENSE=	mit OR apache-2.0

CONFLICTS+=	rust-bin-[0-9]*

# uses -std=c++14
GCC_REQD+=	5

USE_GCC_RUNTIME=	yes
USE_LANGUAGES=		c c++11
USE_LIBTOOL=		yes
USE_TOOLS+=		bash grep gmake perl:build pkg-config

# The NetBSD bootstraps are built for NetBSD 8 (because rust doesn't
# build on 7).  Mark earlier versions as broken.
BROKEN_ON_PLATFORM+=	NetBSD-[1-7].*-*

HAS_CONFIGURE=			yes
PYTHON_FOR_BUILD_ONLY=		yes
CONFIG_SHELL=			${PYTHONBIN}
CONFIGURE_SCRIPT=		src/bootstrap/configure.py
CONFIGURE_ARGS+=		--prefix=${PREFIX}
CONFIGURE_ARGS+=		--mandir=${PREFIX}/${PKGMANDIR}
CONFIGURE_ARGS+=		--sysconfdir=${PKG_SYSCONFDIR}
CONFIGURE_ARGS+=		--python=${PYTHONBIN}
CONFIGURE_ARGS+=		--release-channel=stable
#CONFIGURE_ARGS+=		--enable-local-rust
CONFIGURE_ARGS+=		--local-rust-root=${RUST_BOOTSTRAP_PATH}
CONFIGURE_ARGS+=		--enable-extended	# Build and install cargo too.
CONFIGURE_ARGS+=		--enable-rpath
CONFIGURE_ARGS+=		--disable-codegen-tests
CONFIGURE_ARGS+=		--disable-dist-src
CONFIGURE_ARGS+=		--disable-llvm-static-stdcpp
CONFIGURE_ARGS+=		--disable-ninja
# XXX: to be enabled in the future
#CONFIGURE_ARGS+=		--jemalloc-root=${BUILDLINK_PREFIX.jemalloc}/lib

# Use "dist" build target for cross compile of bootstrap
#BUILD_TARGET=		dist
BUILD_TARGET=		build

# Include (optional) settings to cross-build rust
.include "cross.mk"

# Getting RPATH with $ORIGIN into bootstrap may be troublesome, so
# uncommenting the LD_LIBRARY_PATH setting may be required to run
# the bootstrap
PKGSRC_MAKE_ENV+=	LD_LIBRARY_PATH=${RUST_BOOTSTRAP_PATH:Q}/lib

# This should allow us to perform "offline" builds (so cargo doesn't fetch
# dependencies during the build stage) but this isn't hooked up yet.
CONFIGURE_ARGS+=	--enable-vendor

# cargo defaults to using the number of available CPUs
MAKE_ENV+=		CARGO_BUILD_JOBS=${_MAKE_JOBS_N}

CFLAGS.SunOS+=		-D_POSIX_PTHREAD_SEMANTICS

UNLIMIT_RESOURCES+=	cputime datasize virtualsize

TEST_TARGET=	check

# bin/* lib/*, but names vary
CHECK_RELRO_SUPPORTED=	no
CHECK_SSP_SUPPORTED=	no

.include "../../mk/bsd.prefs.mk"

.if !empty(MACHINE_PLATFORM:MNetBSD-*-powerpc) || \
    !empty(MACHINE_PLATFORM:MNetBSD-*-earmv7hf) || \
    !empty(TARGET:Marmv7-unknown-netbsd-eabihf)
# Bootstrapping on NetBSD/powerpc requires no debug-info from rustc
# (both for amd64->powerpc built and powerpc->powerpc built bootstrap bits)
# Also try to downsize the armv7 build.
CONFIGURE_ARGS+=	--disable-debug
CONFIGURE_ARGS+=	--disable-debug-assertions
CONFIGURE_ARGS+=	--disable-llvm-release-debuginfo
CONFIGURE_ARGS+=	--debuginfo-level=0
CONFIGURE_ARGS+=	--debuginfo-level-rustc=0
CONFIGURE_ARGS+=	--debuginfo-level-std=0
CONFIGURE_ARGS+=	--debuginfo-level-tools=0
CONFIGURE_ARGS+=	--debuginfo-level-tests=0
.endif

# Only build the ARM target on/for this host, due to resource constraints
.if !empty(MACHINE_PLATFORM:MNetBSD-*-earmv7hf)
CONFIGURE_ARGS+=	--set llvm.targets="ARM"
.endif
# When cross-building for ARM on X86, X86 needs to go along due
# to 2-stage build process
.if !empty(TARGET:Marmv7-unknown-netbsd-eabihf)
CONFIGURE_ARGS+=	--set llvm.targets="ARM;X86"
.endif

.if ${OPSYS} == "NetBSD"
# This block contains information about known trouble on NetBSD and workarounds.

# Parallel builds failed on NetBSD due to dynamic linker locking bugs.
# \todo Explain if the build is believed to be sound if not parallel,
# or if a non-parallel build is merely more likely to work.
#
# See toolchain/54192 at
#   http://gnats.netbsd.org/cgi-bin/query-pr-single.pl?number=54192
# which was fixed in -current on 2020-04-19:
#   http://mail-index.netbsd.org/source-changes/2020/04/16/msg116256.html
#   http://mail-index.netbsd.org/source-changes/2020/04/19/msg116337.html
# These  were pulled up to netbsd-9 on 2020-05-13:
#   http://releng.netbsd.org/cgi-bin/req-9.cgi?show=907
# This has not been pulled up to netbsd-8
#   \todo Explain if it's not applicable, shouldn't be pulled up, should be
#   but hasn't, is too hard, etc.
#
# On pkgbuild for 2020Q1 9.0_RELEASE amd64, rust did not build despite
# MAKE_JOBS_SAFE=no, but setting MAKE_JOBS=1 resulted in success. (No
# PR is open for this.)  \todo Understand and fix.
#
# If we aren't on 9-current, and are on 8.x or 9.x, avoid parallel.
# \todo Consider avoiding setting this on netbsd-9 past the fix.
.  if ${MACHINE_PLATFORM:MNetBSD-[1-9].*} && !${MACHINE_PLATFORM:MNetBSD-9.99.*}
MAKE_JOBS_SAFE=	no
.  endif

# Open PRs
#
# Broken package with PREFIX not /usr/pkg:
#   http://gnats.netbsd.org/cgi-bin/query-pr-single.pl?number=54453
#
# NetBSD 8.1 earmv7hf: unknown configure option
#   http://gnats.netbsd.org/cgi-bin/query-pr-single.pl?number=54621

.endif

#
# Under NetBSD, do not use DT_RUNPATH
#
BUILDLINK_TRANSFORM.NetBSD+=	rm:-Wl,--enable-new-dtags

.PHONY: pre-build-fix
#
# Rust unfortunately requires itself to build.  On platforms which aren't
# supported by upstream (where they offer binary bootstraps), or where we do
# not trust random binaries from the Internet, we need to build and provide our
# own bootstrap.  See the stage0-bootstrap below for more details.
#
DISTFILES:=		${DEFAULT_DISTFILES}

.if !empty(MACHINE_PLATFORM:MDarwin-*-x86_64) || make(distinfo) || make (makesum) || make(mdi)
RUST_STAGE0_VER=	1.46.0
RUST_ARCH:=		x86_64-apple-darwin
RUST_STAGE0:=		rust-${RUST_STAGE0_VER}-${RUST_ARCH}.tar.gz
RUST_STD_STAGE0:=	rust-std-${RUST_STAGE0_VER}-${RUST_ARCH}.tar.gz
DISTFILES:=		${DISTFILES} ${RUST_STAGE0} ${RUST_STD_STAGE0}
pre-build-fix:
.endif
.if !empty(MACHINE_PLATFORM:MLinux-*-i386) || make(distinfo) || make (makesum) || make(mdi)
RUST_STAGE0_VER=	1.46.0
RUST_ARCH:=		i686-unknown-linux-gnu
RUST_STAGE0:=		rust-${RUST_STAGE0_VER}-${RUST_ARCH}.tar.gz
RUST_STD_STAGE0:=	rust-std-${RUST_STAGE0_VER}-${RUST_ARCH}.tar.gz
DISTFILES:=		${DISTFILES} ${RUST_STAGE0} ${RUST_STD_STAGE0}
pre-build-fix:
.endif
.if !empty(MACHINE_PLATFORM:MLinux-*-x86_64) || make(distinfo) || make (makesum) || make(mdi)
RUST_STAGE0_VER=	1.46.0
RUST_ARCH:=		x86_64-unknown-linux-gnu
RUST_STAGE0:=		rust-${RUST_STAGE0_VER}-${RUST_ARCH}.tar.gz
RUST_STD_STAGE0:=	rust-std-${RUST_STAGE0_VER}-${RUST_ARCH}.tar.gz
DISTFILES:=		${DISTFILES} ${RUST_STAGE0} ${RUST_STD_STAGE0}
pre-build-fix:
.endif
.if !empty(MACHINE_PLATFORM:MSunOS-*-x86_64) || make(distinfo) || make (makesum) || make(mdi)
RUST_STAGE0_VER=	1.46.0
RUST_ARCH:=		x86_64-sun-solaris
RUST_STAGE0:=		rust-${RUST_STAGE0_VER}-${RUST_ARCH}.tar.gz
SITES.${RUST_STAGE0}=	https://us-east.manta.joyent.com/pkgsrc/public/pkg-bootstraps/
DISTFILES:=		${DISTFILES} ${RUST_STAGE0}
RUST_BOOTSTRAP_PATH?=	${WRKDIR}/rust-${RUST_STAGE0_VER}-${RUST_ARCH}
pre-build-fix:
.endif
.if !empty(MACHINE_PLATFORM:MFreeBSD-*-i386) || make(distinfo) || make (makesum) || make(mdi)
RUST_STAGE0_VER=	1.46.0
RUST_ARCH:=		i686-unknown-freebsd
RUST_STAGE0:=		rust-${RUST_STAGE0_VER}-${RUST_ARCH}.tar.gz
RUST_STD_STAGE0:=	rust-std-${RUST_STAGE0_VER}-${RUST_ARCH}.tar.gz
DISTFILES:=		${DISTFILES} ${RUST_STAGE0} ${RUST_STD_STAGE0}
pre-build-fix:
.endif
.if !empty(MACHINE_PLATFORM:MFreeBSD-*-x86_64) || make(distinfo) || make (makesum) || make(mdi)
RUST_STAGE0_VER=	1.46.0
RUST_ARCH:=		x86_64-unknown-freebsd
RUST_STAGE0:=		rust-${RUST_STAGE0_VER}-${RUST_ARCH}.tar.gz
RUST_STD_STAGE0:=	rust-std-${RUST_STAGE0_VER}-${RUST_ARCH}.tar.gz
DISTFILES:=		${DISTFILES} ${RUST_STAGE0} ${RUST_STD_STAGE0}
pre-build-fix:
.endif
.if !empty(MACHINE_PLATFORM:MNetBSD-*-i386) || make(distinfo) || make (makesum) || make(mdi)
RUST_STAGE0_VER=	1.46.0
RUST_ARCH=		i686-unknown-netbsd
RUST_STAGE0:=		rust-${RUST_STAGE0_VER}-${RUST_ARCH}.tar.gz
RUST_STD_STAGE0:=	rust-std-${RUST_STAGE0_VER}-${RUST_ARCH}.tar.gz
SITES.${RUST_STAGE0}=	${MASTER_SITE_LOCAL:=rust/}
SITES.${RUST_STD_STAGE0}=	${MASTER_SITE_LOCAL:=rust/}
DISTFILES:=		${DISTFILES} ${RUST_STAGE0} ${RUST_STD_STAGE0}
# Setting this changes it for every distfile, which doesn't match what is
# currently in distinfo.
#DIST_SUBDIR=		${PKGNAME}
# For atomic ops
CFLAGS+=		-march=i586
pre-build-fix:
	${TOOLS_PLATFORM.paxctl} +am ${WRKDIR}/rust-bootstrap/bin/cargo
	${TOOLS_PLATFORM.paxctl} +am ${WRKDIR}/rust-bootstrap/bin/rustc
.endif
.if !empty(MACHINE_PLATFORM:MNetBSD-*-x86_64) || make(distinfo) || make (makesum) || make(mdi)
RUST_STAGE0_VER=	1.46.0
RUST_ARCH=		x86_64-unknown-netbsd
RUST_STAGE0:=		rust-${RUST_STAGE0_VER}-${RUST_ARCH}.tar.gz
RUST_STD_STAGE0:=	rust-std-${RUST_STAGE0_VER}-${RUST_ARCH}.tar.gz
DISTFILES:=		${DISTFILES} ${RUST_STAGE0} ${RUST_STD_STAGE0}
pre-build-fix:
.endif
.if !empty(MACHINE_PLATFORM:MNetBSD-*-powerpc) || make(distinfo) || make (makesum) || make(mdi)
RUST_STAGE0_VER=	1.46.0
RUST_ARCH=		powerpc-unknown-netbsd

# Cross-built against NetBSD 9.0
.  if empty(OS_VERSION:M8.*) || make(distinfo) || make(makesum) || make(mdi)
RUST_STAGE0:=			rust-${RUST_STAGE0_VER}-${RUST_ARCH}90.tar.gz
RUST_STD_STAGE0:=		rust-std-${RUST_STAGE0_VER}-${RUST_ARCH}90.tar.gz
DISTFILES:=			${DISTFILES} ${RUST_STAGE0} ${RUST_STD_STAGE0}
SITES.${RUST_STAGE0}=		${MASTER_SITE_LOCAL:=rust/}
SITES.${RUST_STD_STAGE0}=	${MASTER_SITE_LOCAL:=rust/}
.  endif

# Cross-built against NetBSD 8.0
.  if !empty(OS_VERSION:M8.*) || make(distinfo) || make(makesum) || make(mdi)
RUST_STAGE0:=			rust-${RUST_STAGE0_VER}-${RUST_ARCH}.tar.gz
RUST_STD_STAGE0:=		rust-std-${RUST_STAGE0_VER}-${RUST_ARCH}.tar.gz
DISTFILES:=			${DISTFILES} ${RUST_STAGE0} ${RUST_STD_STAGE0}
SITES.${RUST_STAGE0}=		${MASTER_SITE_LOCAL:=rust/}
SITES.${RUST_STD_STAGE0}=	${MASTER_SITE_LOCAL:=rust/}
.  endif

pre-build-fix:
.endif
.if !empty(MACHINE_PLATFORM:MNetBSD-*-aarch64) || make(distinfo) || make (makesum) || make(mdi)
RUST_STAGE0_VER=	1.46.0
RUST_ARCH=		aarch64-unknown-netbsd
RUST_STAGE0:=		rust-${RUST_STAGE0_VER}-${RUST_ARCH}.tar.gz
RUST_STD_STAGE0:=	rust-std-${RUST_STAGE0_VER}-${RUST_ARCH}.tar.gz
DISTFILES:=		${DISTFILES} ${RUST_STAGE0} ${RUST_STD_STAGE0}
SITES.${RUST_STAGE0}=	${MASTER_SITE_LOCAL:=rust/}
SITES.${RUST_STD_STAGE0}=	${MASTER_SITE_LOCAL:=rust/}
pre-build-fix:
.endif
.if !empty(MACHINE_PLATFORM:MNetBSD-*-sparc64) || make(distinfo) || make (makesum) || make(mdi)
RUST_STAGE0_VER=	1.46.0
RUST_ARCH=		sparc64-unknown-netbsd
RUST_STAGE0:=		rust-${RUST_STAGE0_VER}-${RUST_ARCH}.tar.gz
RUST_STD_STAGE0:=	rust-std-${RUST_STAGE0_VER}-${RUST_ARCH}.tar.gz
DISTFILES:=		${DISTFILES} ${RUST_STAGE0} ${RUST_STD_STAGE0}
SITES.${RUST_STAGE0}=	${MASTER_SITE_LOCAL:=rust/}
SITES.${RUST_STD_STAGE0}=	${MASTER_SITE_LOCAL:=rust/}
pre-build-fix:
.endif
.if !empty(MACHINE_PLATFORM:MNetBSD-*-earmv7hf) || make(distinfo) || make (makesum) || make(mdi)
RUST_ARCH=		armv7-unknown-netbsd-eabihf
RUST_STAGE0_VER=	1.46.0
RUST_STAGE0:=		rust-${RUST_STAGE0_VER}-${RUST_ARCH}.tar.gz
RUST_STD_STAGE0:=	rust-std-${RUST_STAGE0_VER}-${RUST_ARCH}.tar.gz
DISTFILES:=		${DISTFILES} ${RUST_STAGE0} ${RUST_STD_STAGE0}
SITES.${RUST_STAGE0}=	${MASTER_SITE_LOCAL:=rust/}
SITES.${RUST_STD_STAGE0}=	${MASTER_SITE_LOCAL:=rust/}
pre-build-fix:
.endif

# You may override RUST_BOOTSTRAP_PATH and RUST_ARCH in mk.conf if you have a local bootstrap compiler.
.if !defined(RUST_ARCH) && !defined(RUST_BOOTSTRAP_PATH)
NOT_FOR_PLATFORM+=	${MACHINE_PLATFORM}
.else
RUST_BOOTSTRAP_PATH?=	${WRKDIR}/rust-bootstrap
.endif

.if ${OPSYS} == "SunOS"
BUILD_DEPENDS+=		coreutils>=0:../../sysutils/coreutils
BUILD_DEPENDS+=		gzip>=0:../../archivers/gzip
TOOLS_CREATE+=		md5sum
TOOLS_PATH.md5sum=	${PREFIX}/bin/gmd5sum
TOOLS_PLATFORM.gzcat=	${PREFIX}/bin/gzip -cd
.endif

SUBST_CLASSES+=		rpath
SUBST_STAGE.rpath=	pre-configure
SUBST_FILES.rpath+=	src/librustc_codegen_ssa/back/linker.rs
SUBST_FILES.rpath+=	src/bootstrap/builder.rs
SUBST_VARS.rpath=	PREFIX

#
# Generate list of subst entries for various .cargo-checksum.json files.  These
# are all handled together in one big substitution to simplify things rather
# than one substitution entry per file, but are kept separate below to ease
# updating and verification.
#
CKSUM_CRATES+=	vendor/libc
CKSUMS+=	9f96e346d87296e2b0b87b9fe375d67fb66cd88ce61ea2905466c8c5891d3108
CKSUMS+=	ebcb0709586e6ed1e8b4538368201638006e26042d464bbc1151bef9eb158f8c

CKSUM_CRATES+=	vendor/lzma-sys
CKSUMS+=	6fd5e9245db34c6f557b8bfcaf03db82fc88c3b06dbfbb5f03b2bcd138983ef9
CKSUMS+=	5e252578b5d266f6a4c8dc9f71ca7a91536ccb8c5c7d7753b82f12ec886459ef

CKSUM_CRATES+=	vendor/stacker
CKSUMS+=	37ef9666d048191eeca23d8f7d99cf912b953cc489bf860107aec306b95b2d99
CKSUMS+=	410f22f5e95860530be1abaaf2e279d2f4226e5c17c2cee302661d8079246b3a

SUBST_CLASSES+=		cksum
SUBST_STAGE.cksum=	pre-configure
.for crate in ${CKSUM_CRATES}
SUBST_FILES.cksum+=	${crate}/.cargo-checksum.json
.endfor
.for from to in ${CKSUMS}
SUBST_SED.cksum+=	-e 's,${from},${to},g'
.endfor

post-extract:
	set -e;									\
	if ${TEST} -e ${WRKDIR}/rust-${RUST_STAGE0_VER}-${RUST_ARCH}/install.sh	\
	  -a ! -e ${RUST_BOOTSTRAP_PATH}/bin/rustc; then \
		cd ${WRKDIR}/rust-${RUST_STAGE0_VER}-${RUST_ARCH};		\
		${TOOLS_BASH} ./install.sh --prefix=${RUST_BOOTSTRAP_PATH};	\
		cd ${WRKDIR}/rust-std-${RUST_STAGE0_VER}-${RUST_ARCH};		\
		${TOOLS_BASH} ./install.sh --prefix=${RUST_BOOTSTRAP_PATH};	\
	fi
.if ${OPSYS} == "NetBSD"
	SDIR=${WRKDIR}/scripts; \
	${MKDIR} $${SDIR}; \
	cd $${SDIR}; \
	${RM} -f c++-wrap; \
	${RM} -f clang++-wrap; \
	${RM} -f clang-wrap; \
	${CP} ${.CURDIR}/files/gcc-wrap .; \
	${CHMOD} +x gcc-wrap; \
	${LN} -s gcc-wrap c++-wrap; \
	${LN} -s gcc-wrap clang++-wrap; \
	${LN} -s gcc-wrap clang-wrap
.endif

.if ${OPSYS} == "FreeBSD"
MAKE_ENV+=		OPENSSL_DIR=${SSLBASE}
.endif

.if ${OPSYS} == "NetBSD" && !empty(PKGSRC_COMPILER:Mclang) && !exists(/lib/libgcc_s.so)
BUILDLINK_TRANSFORM+=	rm:-lgcc_s
MAKE_ENV+=		PKGSRC_HAVE_LIBCPP=yes
.endif

pre-build: pre-build-fix
.if ${OPSYS} == "NetBSD" && !empty(PKGSRC_COMPILER:Mclang) && !exists(/lib/libgcc_s.so)
	cp ${FILESDIR}/libgcc_s.so.1 ${RUST_BOOTSTRAP_PATH}/lib/.
.endif

do-build:
	cd ${WRKSRC} \
	&& ${_ULIMIT_CMD} ${SETENV} ${INSTALL_ENV} ${MAKE_ENV} \
	sh -c "if [ \"${BUILD_TARGET}\" = \"dist\" ]; then \
			unset DESTDIR; \
		fi; \
		${PYTHONBIN} ./x.py -v ${BUILD_TARGET} -j ${_MAKE_JOBS_N}"

do-install:
	cd ${WRKSRC} \
	&& ${_ULIMIT_CMD} ${SETENV} ${INSTALL_ENV} ${MAKE_ENV} \
		${PYTHONBIN} ./x.py -v install -j ${_MAKE_JOBS_N}

.if ${OPSYS} == "Darwin"
.PHONY: fix-darwin-install-name
post-install: fix-darwin-install-name
fix-darwin-install-name:
	for f in ${DESTDIR}${PREFIX}/lib/librustc_macros-*.dylib \
	    ${DESTDIR}${PREFIX}/lib/libtracing_attributes-*.dylib \
	    ${DESTDIR}${PREFIX}/lib/libchalk_derive-*.dylib; do \
		install_name_tool -id `${ECHO} $$f | ${SED} -e 's,${DESTDIR},,g'` $$f; \
	done
.endif

GENERATE_PLIST+=	${FIND} ${DESTDIR}${PREFIX} \( -type f -o -type l \) -print | \
			${SED} -e 's,${DESTDIR}${PREFIX}/,,' | ${SORT} ;

# Create a relocatable stage2 bootstrap from the bits we just built that can be
# used to build the next version of rust.  Currently only tested on SmartOS.
#
BOOTSTRAP_TMPDIR=	${WRKDIR}/${PKGNAME_NOREV}-${RUST_ARCH}
USE_TOOLS+=		gtar

# The NetBSD part is so far untested, because I could not convince
# the rust build to use the gcc wrapper when building natively,
# so that I could get a placeholder in the RPATH, because chrpath
# cannot extend the length of the RPATH...
ELFEDIT?=	/usr/bin/elfedit

.PHONY: stage0-bootstrap
stage0-bootstrap: install
	${RM} -rf ${BOOTSTRAP_TMPDIR}
	${MKDIR} ${BOOTSTRAP_TMPDIR}
.if ${OPSYS} == "NetBSD"
	(cd ${BOOTSTRAP_TMPDIR}; \
	DISTDIR=${WRKSRC}/bild/dist; \
	VER_ARCH=${PKGVERSION}-${RUST_ARCH}; \
	RUSTC=rustc-$${VER_ARCH}; \
	RUSTC_FILE=$${RUSTC}.tar.gz; \
	RUST_STD=rust-std-$${VER_ARCH}; \
	RUST_STD_FILE=$${RUST_STD}.tar.gz; \
	${GTAR} -xzf $${DISTDIR}/$${RUSTC_FILE}; \
		(cd ${RUSTC}; \
	RPATH='/usr/pkg/lib:/lib:/usr/lib:$$ORIGIN/../lib'; \
	for f in rls-preview/bin/rls rustc/bin/rustc rustc/bin/rustdoc; do \
		chrpath -r $$RPATH $$f; \
	done; \
	RPATH='/usr/pkg/lib:/lib:/usr/lib:$$ORIGIN'; \
	for f in rustc/lib/*.so*; do \
		chrpath -r $$RPATH $$f; \
	done; \
	RPATH='/usr/pkg/lib:/lib:/usr/lib:$$ORIGIN:$$ORIGIN/../../..'; \
	for f in rustc/lib/rustlib/*/*/*.so*; do \
		chrpath -r $$RPATH $$f; \
	done;); \
	${GTAR} -czf $${RUSTC_FILE} $${RUSTC}; \
	${CP} $${DISTDIR}/$${RUST_STD_FILE} .; \
	${ECHO} "Fixed stage0 bootstrap in ${BOOTSTRAP_TMPDIR}:"; \
	${ECHO} "$${RUSTC_FILE}"; \
	${ECHO} "$${RUST_STD_FILE}"; \
	)
.endif
.if ${OS_VARIANT} == "SmartOS"
	${CP} -R ${DESTDIR}/${PREFIX}/bin ${BOOTSTRAP_TMPDIR}/
	${CP} -R ${DESTDIR}/${PREFIX}/lib ${BOOTSTRAP_TMPDIR}/
	${MKDIR} ${BOOTSTRAP_TMPDIR}/lib/pkgsrc
	for lib in libgcc_s.so.1 libssp.so.0 libstdc++.so.6; do \
		${CP} `${PKG_CC} -print-file-name=$${lib}` \
		    ${BOOTSTRAP_TMPDIR}/lib/pkgsrc/; \
	done
	# direct dependencies
	for lib in libLLVM-10.so libcrypto.so.1.1 libcurl.so.4 \
		   libssl.so.1.1 libz.so.1; do \
		${CP} ${PREFIX}/lib/$${lib} ${BOOTSTRAP_TMPDIR}/lib/pkgsrc/; \
	done
	# libcurl dependencies
	for lib in libiconv.so.2 libidn2.so.0 libintl.so.8 liblber-2.4.so.2 \
		   libldap-2.4.so.2 libnghttp2.so.14 libsasl2.so.3 \
		   libssh2.so.1 libunistring.so.2; do \
		${CP} ${PREFIX}/lib/$${lib} ${BOOTSTRAP_TMPDIR}/lib/pkgsrc/; \
	done
	for f in ${BOOTSTRAP_TMPDIR}/bin/*; do \
		/bin/file -b "$$f" | grep ^ELF >/dev/null || continue; \
		${ELFEDIT} -e 'dyn:runpath $$ORIGIN/../lib:$$ORIGIN/../lib/pkgsrc' $$f; \
	done
	for f in ${BOOTSTRAP_TMPDIR}/lib/pkgsrc/*.so*; do \
		${ELFEDIT} -e 'dyn:runpath $$ORIGIN' $$f; \
	done
	for f in ${BOOTSTRAP_TMPDIR}/lib/*.so*; do \
		${ELFEDIT} -e 'dyn:runpath $$ORIGIN:$$ORIGIN/pkgsrc' $$f; \
	done
	for f in ${BOOTSTRAP_TMPDIR}/lib/rustlib/*/*/*.so*; do \
		${ELFEDIT} -e 'dyn:runpath $$ORIGIN:$$ORIGIN/../../..:$$ORIGIN/../../../pkgsrc' $$f; \
	done
	(cd ${WRKDIR}; \
	 ${GTAR} -zcf ${PKGNAME_NOREV}-${RUST_ARCH}.tar.gz ${PKGNAME_NOREV}-${RUST_ARCH})
.endif

.include "options.mk"

# These dependencies currently use the bundled sources as they require
# development features not yet available in released versions.
#
#.include "../../devel/libgit2/buildlink3.mk"
#.include "../../security/libssh2/buildlink3.mk"
#.include "../../www/http-parser/buildlink3.mk"
#.include "../../devel/jemalloc/buildlink3.mk"

## Issues specific to: bootstrap AND NetBSD follow

# (I wish this worked on powerpc, but it doesn't since
# I can't build with the internal LLVM, ref.
# https://github.com/rust-lang/rust/issues/65862)

.if (${OPSYS} == "NetBSD") && \
		((${MACHINE_ARCH} == "i386") || \
		 (${MACHINE_ARCH} == "sparc64") || \
		 (${MACHINE_ARCH} == "powerpc")) \
	&& (empty(OS_VERSION:M[012345678].*) || \
	    !empty(OS_VERSION:M8.99.*))
# Bootstrap kits are built on 8.0, so that a single bootstrap can run
# on multiple systems.  Thus later versions need the compat80 package.
# \todo Explain why this is limited to a small list of architectures,
# and in particular why not x86_64.
DEPENDS+=	compat80>=0:../../emulators/compat80
.endif

.if (${MACHINE_ARCH} == "powerpc")
# LLVM needs libatomic for 64-bit atomics on powerpc
.include "../../devel/libatomic/buildlink3.mk"
.endif

.if (${OPSYS} == "NetBSD") && \
		((${MACHINE_ARCH} == "i386")) \
	&& (empty(OS_VERSION:M[012345678].*) || \
	    !empty(OS_VERSION:M8.99.*))
# Bootstrap kits use openssl, which on NetBSD 8 comes from pkgsrc.
# Therefore the pkgsrc openssl libs need to be present as well.
# The 1.44.1 i686 bootstrap links with pkgsrc openssl.  The others do
# not.  When the package is built,
# cargo links against pkgsrc openssl, so it must be a run-time
# dependency as well.  Forcing USE_BUILTIN.openssl=no results in a
# mysterious heimdal error, but straight DEPENDS seems to result in a
# satisfactory package build.
# While this is icky, it is for the time being better than no rust package.
DEPENDS+=	openssl>=1.1:../../security/openssl
.endif

.include "../../devel/zlib/buildlink3.mk"
.include "../../lang/python/tool.mk"
.include "../../security/openssl/buildlink3.mk"
BUILDLINK_API_DEPENDS.curl+= curl>=7.67.0
.include "../../www/curl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
