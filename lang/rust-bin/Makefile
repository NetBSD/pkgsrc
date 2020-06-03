# $NetBSD: Makefile,v 1.7 2020/06/03 10:45:04 nia Exp $

DISTNAME=	rust-1.42.0
CATEGORIES=	lang
MASTER_SITES=	https://static.rust-lang.org/dist/
PKGREVISION=	1

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://rust-lang.org/
COMMENT=	Safe, concurrent, practical language (official binaries)
LICENSE=	mit OR apache-2.0

.include "../../lang/rust/type.mk"

.if ${RUST_TYPE} != "bin"
PKG_SKIP_REASON+=	"Rust binary package, RUST_TYPE is src"
.endif

ONLY_FOR_PLATFORM+=	Darwin-*-x86_64
ONLY_FOR_PLATFORM+=	FreeBSD-*-i386
ONLY_FOR_PLATFORM+=	FreeBSD-*-x86_64
ONLY_FOR_PLATFORM+=	NetBSD-*-x86_64
ONLY_FOR_PLATFORM+=	Linux-*-aarch64
ONLY_FOR_PLATFORM+=	Linux-*-i386
ONLY_FOR_PLATFORM+=	Linux-*-x86_64

CHECK_RELRO_SKIP+=	lib/rustlib/x86_64-unknown-netbsd/bin/llvm-ar
CHECK_RELRO_SKIP+=	lib/rustlib/x86_64-unknown-netbsd/bin/llvm-nm
CHECK_RELRO_SKIP+=	lib/rustlib/x86_64-unknown-netbsd/bin/llvm-objcopy
CHECK_RELRO_SKIP+=	lib/rustlib/x86_64-unknown-netbsd/bin/llvm-objdump
CHECK_RELRO_SKIP+=	lib/rustlib/x86_64-unknown-netbsd/bin/llvm-profdata
CHECK_RELRO_SKIP+=	lib/rustlib/x86_64-unknown-netbsd/bin/llvm-readobj
CHECK_RELRO_SKIP+=	lib/rustlib/x86_64-unknown-netbsd/bin/llvm-size
CHECK_RELRO_SKIP+=	lib/rustlib/x86_64-unknown-netbsd/bin/llvm-strip

# The NetBSD bootstraps are built for NetBSD 8 (because rust doesn't
# build on 7).  Mark earlier versions as broken.
BROKEN_ON_PLATFORM+=	NetBSD-[1-7].*-*

NO_BUILD=	yes
USE_TOOLS+=	bash
WRKSRC=		${WRKDIR}/${DISTFILES:S/.tar.gz//}

GENERATE_PLIST+=	find ${DESTDIR}${PREFIX} \( -type f -o -type l \) -print | \
			sed 's,${DESTDIR}${PREFIX}/,,' | ${SORT} ;

INSTALLATION_DIRS=	bin ${PKGMANDIR} share/doc/cargo/bash_completion.d

.include "../../mk/bsd.prefs.mk"

DISTFILES:=	# empty

.if !empty(MACHINE_PLATFORM:MDarwin-*-x86_64) || make(distinfo) || make(makesum) || make(mdi)
RUST_ARCH:=	x86_64-apple-darwin
DISTFILES:=	${DISTFILES} ${DISTNAME}-${RUST_ARCH}.tar.gz
.endif
.if !empty(MACHINE_PLATFORM:MFreeBSD-*-x86_64) || make(distinfo) || make(makesum) || make(mdi)
RUST_ARCH:=	x86_64-unknown-freebsd
DISTFILES:=	${DISTFILES} ${DISTNAME}-${RUST_ARCH}.tar.gz
.endif
.if !empty(MACHINE_PLATFORM:MFreeBSD-*-i386) || make(distinfo) || make(makesum) || make(mdi)
RUST_ARCH:=	i686-unknown-freebsd
DISTFILES:=	${DISTFILES} ${DISTNAME}-${RUST_ARCH}.tar.gz
.endif
.if !empty(MACHINE_PLATFORM:MLinux-*-i386) || make(distinfo) || make(makesum) || make(mdi)
RUST_ARCH:=	i686-unknown-linux-gnu
DISTFILES:=	${DISTFILES} ${DISTNAME}-${RUST_ARCH}.tar.gz
.endif
.if (!empty(MACHINE_PLATFORM:MLinux-*-aarch64) && !empty(GLIBC_VERSION)) || make(distinfo) || make(makesum) || make(mdi)
RUST_ARCH:=	aarch64-unknown-linux-gnu
DISTFILES:=	${DISTFILES} ${DISTNAME}-${RUST_ARCH}.tar.gz
.endif
.if (!empty(MACHINE_PLATFORM:MLinux-*-x86_64) && !empty(GLIBC_VERSION)) || make(distinfo) || make(makesum) || make(mdi)
RUST_ARCH:=	x86_64-unknown-linux-gnu
DISTFILES:=	${DISTFILES} ${DISTNAME}-${RUST_ARCH}.tar.gz
.endif
.if (!empty(MACHINE_PLATFORM:MLinux-*-x86_64) && empty(GLIBC_VERSION)) || make(distinfo) || make(makesum) || make(mdi)
RUST_ARCH:=	x86_64-unknown-linux-musl
DISTFILES:=	${DISTFILES} ${DISTNAME}-${RUST_ARCH}.tar.gz
.endif
.if !empty(MACHINE_PLATFORM:MNetBSD-*-x86_64) || make(distinfo) || make(makesum) || make(mdi)
.  if empty(OS_VERSION:M[0-8].*)
DEPENDS+=	compat80-[0-9]*:../../emulators/compat80
.  endif
RUST_ARCH:=	x86_64-unknown-netbsd
DISTFILES:=	${DISTFILES} ${DISTNAME}-${RUST_ARCH}.tar.gz
.endif

do-install:
	cd ${WRKSRC} && env PKGMANDIR=${PKGMANDIR} bash ./install.sh \
	--destdir=${DESTDIR} --prefix=${PREFIX}
	${RM} -f ${DESTDIR}${PREFIX}/lib/rustlib/install.log
	${RM} -f ${DESTDIR}${PREFIX}/lib/rustlib/manifest-*
	${RM} -f ${DESTDIR}${PREFIX}/lib/rustlib/uninstall.sh

.if ${OPSYS} == "Darwin"
.PHONY: fix-darwin-install-name
post-install: fix-darwin-install-name
fix-darwin-install-name:
.  for bin in cargo-miri clippy-driver miri rls rustc rustdoc
	otool -XL ${DESTDIR}${PREFIX}/bin/${bin}			\
	    | ${GREP} '@rpath' | while read rpath rest; do		\
		install_name_tool -change $$rpath			\
		    `${ECHO} $$rpath | ${SED} -e 's,@rpath,${PREFIX}/lib,g'` \
		    ${DESTDIR}${PREFIX}/bin/${bin};			\
	done
.  endfor
.  for bin in lldb lldb-mi llvm-nm llvm-objcopy llvm-objdump 		\
		llvm-profdata llvm-readobj llvm-size llvm-strip
	otool -XL ${DESTDIR}${PREFIX}/lib/rustlib/${RUST_ARCH}/bin/${bin} \
	    | ${GREP} '@rpath' | while read rpath rest; do		\
		install_name_tool -change $$rpath			\
		    `${ECHO} $$rpath | ${SED} -e 's,@rpath,${PREFIX}/lib/rustlib/${RUST_ARCH}/lib,g'` \
		    ${DESTDIR}${PREFIX}/lib/rustlib/${RUST_ARCH}/bin/${bin}; \
	done
.  endfor
.  for lib in lib lib/rustlib/${RUST_ARCH}/lib lib/rustlib/${RUST_ARCH}/codegen-backends
	for f in ${DESTDIR}${PREFIX}/${lib}/lib*.dylib; do		\
		[ ! -f $$f ] && continue;				\
		install_name_tool -id `${ECHO} $$f | ${SED} -e 's,${DESTDIR},,g'` $$f; \
		otool -XL $$f | grep '@rpath' | while read rpath rest; do \
			install_name_tool -change $$rpath \
			    `${ECHO} $$rpath | ${SED} -e 's,@rpath,${PREFIX}/lib,g'` \
			    $$f;					\
		done;							\
	done
	install_name_tool -id ${PREFIX}/lib/rustlib/${RUST_ARCH}/lib/python2.7/site-packages/lldb/_lldb.so \
		${DESTDIR}${PREFIX}/lib/rustlib/${RUST_ARCH}/lib/python2.7/site-packages/lldb/_lldb.so
.  endfor
.else
TOOL_DEPENDS+=		patchelf-[0-9]*:../../devel/patchelf

# ld.elf_so in NetBSD 8.x only obeys RPATH, not RUNPATH, so force RPATH there.
FORCE_RPATH=
# The llvm utilities need a specific libstdc++ version from compat80
.  if ${OPSYS} == "NetBSD" && empty(OS_VERSION:M[0-8].*)
RUST_LLVM_RPATH=	${PREFIX}/emul/netbsd/usr/lib:${PREFIX}/lib
.  else
RUST_LLVM_RPATH=	${PREFIX}/lib
FORCE_RPATH=	--force-rpath
.  endif

.PHONY: fix-relative-rpath
post-install: fix-relative-rpath
fix-relative-rpath:
.  for bin in cargo-miri clippy-driver miri rls rustc rustdoc
	${PREFIX}/bin/patchelf ${FORCE_RPATH} --set-rpath \
		${PREFIX}/lib ${DESTDIR}${PREFIX}/bin/${bin}
.  endfor
.  for bin in llvm-ar llvm-nm llvm-objcopy llvm-objdump llvm-profdata \
		llvm-readobj llvm-size llvm-strip
	${PREFIX}/bin/patchelf ${FORCE_RPATH} --set-rpath ${RUST_LLVM_RPATH} \
		${DESTDIR}${PREFIX}/lib/rustlib/${RUST_ARCH}/bin/${bin}
.  endfor
.  for lib in lib lib/rustlib/${RUST_ARCH}/lib \
		lib/rustlib/${RUST_ARCH}/codegen-backends
	for f in ${DESTDIR}${PREFIX}/${lib}/lib*.so; do			\
		[ ! -f $$f ] && continue;				\
		${PREFIX}/bin/patchelf ${FORCE_RPATH} --set-rpath ${PREFIX}/lib $$f;	\
	done
.  endfor
.endif

.include "../../mk/bsd.pkg.mk"
