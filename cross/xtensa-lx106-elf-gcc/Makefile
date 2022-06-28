# $NetBSD: Makefile,v 1.7 2022/06/28 11:31:17 wiz Exp $

# using configure options and sources from
# https://github.com/earlephilhower/esp-quick-toolchain

DISTNAME=		gcc-xtensa-4.8.2
PKGNAME=		${DISTNAME:C/gcc-xtensa/xtensa-lx106-elf-gcc/}
PKGREVISION=		3
CATEGORIES=		cross
MASTER_SITES=		${MASTER_SITE_GITHUB:=jcmvbkbc/}
GITHUB_PROJECT=		gcc-xtensa
GITHUB_TAG=		a0936f8b396491bc7894c8bc5e80971cc9138e94

DIST_SUBDIR=		${PKGNAME_NOREV}

# Custom xtensa newlib       
DISTFILES=		${DEFAULT_DISTFILES}
DISTFILES+=		newlib-${NEWLIBVER}.tar.gz
NEWLIBVER=		xtensa-2_2_0-lock-arduino_20190913
SITES.newlib-${NEWLIBVER}.tar.gz= -https://github.com/earlephilhower/newlib-xtensa/archive/b350aadd0c7f44d5ec867494a795a0eed972ee9a.tar.gz

# extra patches
.for _p in \
    gcc-ctype-inline-pgmread.patch  \
    gcc-docs.patch  \
    gcc-enable-mforcel32-eh.patch  \
    gcc-exception-emergency.patch  \
    gcc-exception-what-to-pmem.patch  \
    gcc-file-shortname.patch  \
    gcc-fix-defaults-h-gcc7.patch  \
    gcc-fix-elfos-h-gcc7.patch  \
    gcc-gmpn_invert_limb.patch  \
    gcc-libc_name_p-fix.patch  \
    gcc-mforce-l32-jcmvbkbc.patch  \
    gcc-osx-malloc.patch  \
    gcc-stdcsupp-safe.patch  \
    gcc-unwind-safe.patch
PATCHFILES+= ${_p}
.endfor
PATCH_SITES+= https://raw.githubusercontent.com/earlephilhower/esp-quick-toolchain/master/patches/gcc4.8/

PATCHFILES+= gcc-001-jump-tables-in-text-section-earlephilhower.patch
PATCH_SITES+= https://github.com/earlephilhower/esp-quick-toolchain/raw/master/patches/
PATCH_DIST_STRIP= -p1

MAINTAINER=		bouyer@NetBSD.org
HOMEPAGE=		https://github.com/espressif/gcc
COMMENT=		Cross GCC for Espressif ESP8266 bare metal environment
LICENSE=		gnu-gpl-v2 AND gnu-gpl-v3 AND gnu-lgpl-v2 AND gnu-lgpl-v3

DEPENDS+=	xtensa-lx106-elf-binutils-[0-9]*:../../cross/xtensa-lx106-elf-binutils

FILESDIR=	${.CURDIR}/../../cross/xtensa-lx106-elf-binutils/files

GNU_CONFIGURE=		yes
INFO_FILES=		yes
USE_LANGUAGES+=		c c++03
USE_TOOLS+=		bash gmake makeinfo perl

# for http://gcc.gnu.org/bugzilla/show_bug.cgi?id=33549
# use makeinfo from pkgsrc/devel/gtexinfo.
TOOL_DEPENDS+=		gtexinfo>=5.1:../../devel/gtexinfo
_TOOLS_USE_PKGSRC.makeinfo= yes

OBJDIR=			../build
CONFIGURE_DIRS=		${OBJDIR}
CONFIGURE_SCRIPT=	${WRKSRC}/configure
CONFIG_SHELL=		${TOOLS_PATH.bash}
WRAPPER_SHELL=		${TOOLS_PATH.bash}
GNU_CONFIGURE_PREFIX=	${PREFIX}/xtensa-lx106-elf

CONFIGURE_ARGS+=	--enable-languages=c,c++
CONFIGURE_ARGS+=	--target=xtensa-lx106-elf
CONFIGURE_ARGS+=	--disable-shared
CONFIGURE_ARGS+=	--with-newlib
CONFIGURE_ARGS+=	--enable-threads=no
CONFIGURE_ARGS+=	--disable-__cxa_atexit
CONFIGURE_ARGS+=	--disable-libgomp
CONFIGURE_ARGS+=	--disable-libmudflap
CONFIGURE_ARGS+=	--disable-nls
CONFIGURE_ARGS+=	--disable-multilib
CONFIGURE_ARGS+=	--disable-bootstrap
CONFIGURE_ARGS+=	--enable-languages=c,c++
CONFIGURE_ARGS+=	--enable-lto
CONFIGURE_ARGS+=	--enable-static=yes
CONFIGURE_ARGS+=	--disable-libstdcxx-verbose

CHECK_PORTABILITY_SKIP+=	contrib/*

post-extract:
	${LN} -s ${WRKDIR}/newlib-*/newlib ${WRKSRC}/newlib
	${LN} -s ${WRKDIR}/newlib-*/libgloss ${WRKSRC}/libgloss

pre-configure:
	${MKDIR} ${WRKSRC}/${OBJDIR}
	${CP} ${FILESDIR}/xtensa-config.h ${WRKSRC}/include/xtensa-config.h

.include "../../devel/gmp/buildlink3.mk"
.include "../../math/mpfr/buildlink3.mk"
.include "../../math/mpcomplex/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
