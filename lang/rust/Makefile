# $NetBSD: Makefile,v 1.5 2016/11/14 20:56:10 ryoon Exp $

DISTNAME=	rustc-1.11.0-src
PKGNAME=	${DISTNAME:S/rustc/rust/:S/-src//}
PKGREVISION=	1
CATEGORIES=	lang
MASTER_SITES=	http://static.rust-lang.org/dist/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.rust-lang.org/
COMMENT=	Safe, concurrent, practical language
LICENSE=	mit OR apache-2.0

WRKSRC=		${WRKDIR}/${DISTNAME:S/-src//}

USE_GCC_RUNTIME=	yes
USE_LANGUAGES=		c c++
USE_TOOLS+=		bash gmake

HAS_CONFIGURE=		yes
CONFIGURE_ARGS+=	--prefix=${PREFIX}
CONFIGURE_ARGS+=	--build=${RUST_ARCH}
CONFIGURE_ARGS+=	--mandir=${PREFIX}/${PKGMANDIR}
CONFIGURE_ARGS+=	--release-channel=stable
CONFIGURE_ENV+=		CFG_DISABLE_CODEGEN_TESTS=1

UNLIMIT_RESOURCES+=	cputime

REPLACE_BASH+=	src/rust-installer/gen-install-script.sh
REPLACE_BASH+=	src/rust-installer/gen-installer.sh

#
# Lots of per-platform specific documentation, e.g. for each system call,
# making it difficult to PLIST.  If it ends up being important we'll just have
# to go with lots of PLIST.${OPSYS}
#
CONFIGURE_ARGS+=	--disable-docs

TEST_TARGET=	check

# Required for LLVM (-std=c++11)
GCC_REQD+=	4.8

.include "../../mk/bsd.prefs.mk"

#
# Use jemalloc on systems where rust does by default too.
#
PLIST_VARS+=		jemalloc
.if ${OPSYS} == "Linux" || ${OPSYS} == "Darwin"
.  include "../../devel/jemalloc/buildlink3.mk"
CONFIGURE_ARGS+=	--jemalloc-root=${BUILDLINK_PREFIX.jemalloc}/lib
PLIST.jemalloc=		yes
.else
CONFIGURE_ARGS+=	--disable-jemalloc
.endif

#
# Under NetBSD, do not use DT_RUNPATH
#
BUILDLINK_TRANSFORM.NetBSD+=	rm:-Wl,--enable-new-dtags

#
# Can't use pkgsrc llvm on SunOS at the moment due to a relocation error.
#
.if ${OPSYS} != "SunOS"
.  include "../../lang/llvm/buildlink3.mk"
CONFIGURE_ARGS+=	--llvm-root=${BUILDLINK_PREFIX.llvm}
.endif

#
# Rust unfortunately requires itself to build.  On platforms which aren't
# supported by upstream (where they offer binary bootstraps), or where we
# do not trust random binaries from the Internet, we need to build and
# provide our own bootstrap.
#
# pkgsrc can be used to do this, but the resulting bootstrap must be
# relocatable (i.e. $ORIGIN) and not depend on anything from pkgsrc (so it
# is common to use rust's internal llvm).
#
# The following variables need to be modified/commented out when producing
# a stage2 bootstrap.
#
CONFIGURE_ARGS+=	--enable-local-rust
CONFIGURE_ARGS+=	--local-rust-root=${WRKDIR}/rust-${RUST_STAGE2_VER}-${RUST_ARCH}/rustc
#
.if !empty(MACHINE_PLATFORM:MDarwin-*-i386)
RUST_ARCH=		i686-apple-darwin
.elif !empty(MACHINE_PLATFORM:MDarwin-*-x86_64)
RUST_ARCH=		x86_64-apple-darwin
.elif !empty(MACHINE_PLATFORM:MLinux-*-i386)
RUST_ARCH=		i686-unknown-linux-gnu
.elif !empty(MACHINE_PLATFORM:MLinux-*-x86_64)
RUST_ARCH=		x86_64-unknown-linux-gnu
.elif !empty(MACHINE_PLATFORM:MSunOS-*-x86_64)
RUST_ARCH=		x86_64-sun-solaris
SITES.${RUST_STAGE2}=	https://us-east.manta.joyent.com/pkgsrc/public/tmp/
.elif !empty(MACHINE_PLATFORM:MNetBSD-*-x86_64)
RUST_ARCH=		x86_64-unknown-netbsd
.else
NOT_FOR_PLATFORM+=	${MACHINE_PLATFORM}
.endif

.if defined(RUST_ARCH)
RUST_STAGE2_VER=	1.10.0
RUST_STAGE2?=		rust-${RUST_STAGE2_VER}-${RUST_ARCH}.tar.gz
SITES.${RUST_STAGE2}?=	https://static.rust-lang.org/dist/
DISTFILES=		${DEFAULT_DISTFILES} ${RUST_STAGE2}
.endif

PLIST_SRC=		PLIST
.if ${OPSYS} == "Darwin"
PLIST_SRC+=		PLIST.lldb
.else
PLIST_SRC+=		PLIST.gdb
.endif

OPSYSVARS+=		SOEXT
SOEXT.Darwin=		dylib
SOEXT.*=		so

RUST_VERHASH=		39b92f95
PLIST_SUBST+=		RUST_ARCH=${RUST_ARCH:Q}
PLIST_SUBST+=		RUST_VERHASH=${RUST_VERHASH:Q}
PLIST_SUBST+=		SOEXT=${SOEXT:Q}
PRINT_PLIST_AWK+=	{ gsub(/${RUST_ARCH}/, "$${RUST_ARCH}") }
PRINT_PLIST_AWK+=	{ gsub(/${RUST_VERHASH}/, "$${RUST_VERHASH}") }
PRINT_PLIST_AWK+=	{ gsub(/\.${SOEXT}/, ".$${SOEXT}") }

.if ${OPSYS} == "SunOS"
BUILD_DEPENDS+=		grep>=0:../../textproc/grep
BUILD_DEPENDS+=		coreutils>=0:../../sysutils/coreutils
TOOLS_PATH.grep=	${PREFIX}/bin/ggrep
TOOLS_CREATE+=		md5sum
TOOLS_PATH.md5sum=	${PREFIX}/bin/gmd5sum

SUBST_CLASSES+=		ranlib
SUBST_STAGE.ranlib=	pre-configure
SUBST_FILES.ranlib=	mk/rt.mk
SUBST_SED.ranlib=	-e 's,RANLIB=.* \\,RANLIB="true" \\,g'
.endif

post-install:
	${RM} -f ${DESTDIR}${PREFIX}/lib/rustlib/install.log

.if ${OPSYS} == "Darwin"
.PHONY: fix-darwin-install-name
post-install: fix-darwin-install-name
fix-darwin-install-name:
.  for bin in rustc rustdoc
	otool -XL ${DESTDIR}${PREFIX}/bin/${bin}			\
	    | ${GREP} '@rpath' | while read rpath rest; do		\
		install_name_tool -change $$rpath			\
		    `${ECHO} $$rpath | ${SED} -e 's,@rpath,${PREFIX}/lib,g'` \
		    ${DESTDIR}${PREFIX}/bin/${bin};			\
	done
.  endfor
.  for libdir in lib lib/rustlib/${RUST_ARCH}/lib
	for f in ${DESTDIR}${PREFIX}/${libdir}/lib*.dylib; do		\
		[ ! -f $$f ] && continue;				\
		install_name_tool -id `${ECHO} $$f | ${SED} -e 's,${DESTDIR},,g'` $$f; \
		otool -XL $$f | grep '@rpath' | while read rpath rest; do \
			install_name_tool -change $$rpath \
			    `${ECHO} $$rpath | ${SED} -e 's,@rpath,${PREFIX}/${libdir},g'` \
			    $$f;					\
		done;							\
	done
.  endfor
.endif

.include "../../devel/cmake/buildlink3.mk"
.include "../../lang/python/tool.mk"
.include "../../mk/bsd.pkg.mk"
