# $NetBSD: Makefile,v 1.2 2024/07/22 20:05:38 tnn Exp $

DISTNAME=		espressif-gcc-13.2.0-${GITHUB_TAG}
PKGNAME=		xtensa-esp-elf-gcc-13.2.0
CATEGORIES=		cross
MASTER_SITES=		${MASTER_SITE_GITHUB:=espressif/}
GITHUB_PROJECT=		gcc
GITHUB_TAG=		8b450d265fc2e60f5be980feb6c9f9c214c6c298
# Espressif overlays
DISTFILES=		${DEFAULT_DISTFILES}
DISTFILES+=		crosstool-NG-esp-13.2.0_20240530-src.tar.xz
SITES.crosstool-NG-esp-13.2.0_20240530-src.tar.xz=	\
	-https://github.com/espressif/crosstool-NG/releases/download/esp-13.2.0_20240530/crosstool-NG-esp-13.2.0_20240530-src.tar.xz

# Custom ESP32 newlib
DISTFILES+=		newlib-${NEWLIBVER}.tar.gz
NEWLIBVER=		esp-4.3.0_20240530
SITES.newlib-${NEWLIBVER}.tar.gz= \
	-https://github.com/espressif/newlib-esp32/archive/refs/tags/esp-4.3.0_20240530.tar.gz

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://github.com/espressif/gcc
COMMENT=		Cross GCC for Espressif ESP32 bare metal environment
LICENSE=		gnu-gpl-v2 AND gnu-gpl-v3 AND gnu-lgpl-v2 AND gnu-lgpl-v3

DEPENDS+=	xtensa-esp-elf-binutils>=2.41.0:../../cross/xtensa-esp-elf-binutils

GNU_CONFIGURE=		yes
INFO_FILES=		yes
USE_LANGUAGES+=		c c++
USE_TOOLS+=		bash gmake makeinfo perl

TOOL_DEPENDS+=		gtexinfo>=5.1:../../devel/gtexinfo
_TOOLS_USE_PKGSRC.makeinfo=	yes

OBJDIR=			../build
CONFIGURE_DIRS=		${OBJDIR}
CONFIGURE_SCRIPT=	${WRKSRC}/configure
CONFIG_SHELL=		${TOOLS_PATH.bash}
WRAPPER_SHELL=		${TOOLS_PATH.bash}
GNU_CONFIGURE_PREFIX=	${PREFIX}/xtensa-esp-elf
MKPIE_SUPPORTED=	no

CONFIGURE_ENV+=		CFLAGS_FOR_TARGET="-mlongcalls"
# This is based on "gcc -v" output from the binary release
CONFIGURE_ARGS+=	--target=xtensa-esp-elf
CONFIGURE_ARGS+=	--exec_prefix=${GNU_CONFIGURE_PREFIX}
CONFIGURE_ARGS+=	--with-local-prefix=${GNU_CONFIGURE_PREFIX}/xtensa-esp-elf
CONFIGURE_ARGS+=	--with-sysroot=${GNU_CONFIGURE_PREFIX}/xtensa-esp-elf
CONFIGURE_ARGS+=	--with-native-system-header-dir=/nonexistent/include
CONFIGURE_ARGS+=	--with-newlib
CONFIGURE_ARGS+=	--enable-threads=no
CONFIGURE_ARGS+=	--disable-shared
CONFIGURE_ARGS+=	--with-pkgversion="${PKGNAME} (pkgsrc)"
CONFIGURE_ARGS+=	--disable-__cxa_atexit
CONFIGURE_ARGS+=	--enable-cxx-flags=-ffunction-sections
CONFIGURE_ARGS+=	--disable-libgomp
CONFIGURE_ARGS+=	--disable-libmudflap
CONFIGURE_ARGS+=	--disable-libmpx
CONFIGURE_ARGS+=	--disable-libssp
CONFIGURE_ARGS+=	--disable-libquadmath
CONFIGURE_ARGS+=	--disable-libquadmath-support
CONFIGURE_ARGS+=	--disable-libstdcxx-verbose
CONFIGURE_ARGS+=	--with-gmp=${BUILDLINK_PREFIX.gmp}
CONFIGURE_ARGS+=	--with-mpfr=${BUILDLINK_PREFIX.mpfr}
CONFIGURE_ARGS+=	--with-mpc=${BUILDLINK_PREFIX.mpcomplex}
CONFIGURE_ARGS+=	--with-isl=${BUILDLINK_PREFIX.isl}
CONFIGURE_ARGS+=	--enable-lto
CONFIGURE_ARGS+=	--enable-target-optspace
CONFIGURE_ARGS+=	--without-long-double-128
CONFIGURE_ARGS+=	--disable-nls
CONFIGURE_ARGS+=	--enable-multiarch
CONFIGURE_ARGS+=	--enable-languages=c,c++
CONFIGURE_ARGS+=	--disable-libstdcxx-verbose
CONFIGURE_ARGS+=	--enable-threads=posix
CONFIGURE_ARGS+=	--enable-gcov-custom-rtio
CONFIGURE_ARGS+=	--enable-libstdcxx-time=yes
CONFIGURE_ARGS+=	--enable-multilib

CONFIGURE_ARGS+=	--disable-bootstrap

# configry for newlib
CONFIGURE_ARGS+=	--disable-newlib-io-c99-formats
CONFIGURE_ARGS+=	--disable-newlib-supplied-syscalls
CONFIGURE_ARGS+=	--enable-newlib-nano-formatted-io
CONFIGURE_ARGS+=	--enable-newlib-reent-small
CONFIGURE_ARGS+=	--enable-target-optspace
CONFIGURE_ARGS+=	--enable-newlib-nano-malloc
CONFIGURE_ARGS+=	--enable-newlib-retargetable-locking
CONFIGURE_ARGS+=	--disable-newlib_wide_orient
CONFIGURE_ARGS+=	--enable-newlib-iconv
CONFIGURE_ARGS+=	--enable-newlib-reent-binary-compat

CHECK_PORTABILITY_SKIP+=	contrib/*
CHECK_PORTABILITY_SKIP+=	gcc/configure	# CONFIG_SHELL is bash
CHECK_PORTABILITY_SKIP+=	gcc/config/nvptx/gen-opt.sh

SUBST_CLASSES+=		prefix
SUBST_FILES.prefix=	gcc/config/xtensa/xtensa-dynconfig.cc
SUBST_STAGE.prefix=	pre-configure
SUBST_MESSAGE.prefix=	Substitute GNU_CONFIGURE_PREFIX in patch
SUBST_VARS.prefix+=	GNU_CONFIGURE_PREFIX

post-extract:
	mv ${WRKDIR}/newlib-*/newlib ${WRKSRC}/newlib
	mv ${WRKDIR}/newlib-*/libgloss ${WRKSRC}/libgloss
#	${CP} -r ${WRKDIR}/crosstool-NG-esp-13.2.0_20240530-src/overlays/xtensa_${ESP32_TYPE}/gcc/. ${WRKSRC}/.
#	${CP} -r ${WRKDIR}/crosstool-NG-esp-13.2.0_20240530-src/overlays/xtensa_${ESP32_TYPE}/newlib/. ${WRKSRC}/.

pre-configure:
	${RUN} cd ${WRKSRC} && ${MKDIR} ${OBJDIR}

.include "../../devel/gmp/buildlink3.mk"
.include "../../math/mpfr/buildlink3.mk"
.include "../../math/mpcomplex/buildlink3.mk"
.include "../../math/isl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
