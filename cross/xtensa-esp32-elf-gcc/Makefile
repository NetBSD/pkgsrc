# $NetBSD: Makefile,v 1.3 2019/06/08 10:53:29 rillig Exp $

# We could use the upstream GCC distfile, but Espressif has important vendor
# patches in their branch and it seems not worth the maintenance overhead to
# extract them and put them in pkgsrc.
# See: https://github.com/espressif/gcc/commits/esp32-2018r1_gcc-8_2_0
#DISTNAME=		gcc-8.3.0
#MASTER_SITES=		${MASTER_SITE_GNU:=gcc/gcc-${PKGVERSION_NOREV}/}
#EXTRACT_SUFX=		.tar.xz

DISTNAME=		espressif-gcc-8.2.0
PKGREVISION=		1
PKGNAME=		${DISTNAME:C/.*gcc/xtensa-esp32-elf-gcc/}
CATEGORIES=		cross
MASTER_SITES=		${MASTER_SITE_GITHUB:=espressif/}
GITHUB_PROJECT=		gcc
GITHUB_TAG=		35d9a8eb86910a6acac7579f22f8e88a92dbb251
# Espressif overlays
DISTFILES=		${DEFAULT_DISTFILES}
DISTFILES+=		crosstool-ng-esp32-2019r1.tar.gz
SITES.crosstool-ng-esp32-2019r1.tar.gz=	\
	-https://github.com/espressif/crosstool-NG/archive/ce035ad3351127e4fdb3ff96790caba42b9f1aa3.tar.gz
# Custom ESP32 newlib
DISTFILES+=		newlib-${NEWLIBVER}.tar.gz
NEWLIBVER=		esp32-2019r1_newlib-3_0_0
SITES.newlib-${NEWLIBVER}.tar.gz= \
	-https://github.com/espressif/newlib-esp32/archive/46a44cc1111687d8297e35f9766493abd291e5cc.tar.gz

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://github.com/espressif/gcc
COMMENT=		Cross GCC for Espressif ESP32 bare metal environment
LICENSE=		gnu-gpl-v2 AND gnu-gpl-v3 AND gnu-lgpl-v2 AND gnu-lgpl-v3

DEPENDS+=	xtensa-esp32-elf-binutils-[0-9]*:../../cross/xtensa-esp32-elf-binutils

GNU_CONFIGURE=		yes
INFO_FILES=		yes
USE_LANGUAGES+=		c c++
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
GNU_CONFIGURE_PREFIX=	${PREFIX}/xtensa-esp32-elf

CONFIGURE_ARGS+=	--target=xtensa-esp32-elf
CONFIGURE_ARGS+=	--enable-languages=c,c++
CONFIGURE_ARGS+=	--with-newlib
CONFIGURE_ARGS+=	--enable-multiarch
CONFIGURE_ARGS+=	--disable-nls
CONFIGURE_ARGS+=	--disable-libstdcxx-pch
CONFIGURE_ARGS+=	--disable-libstdcxx-verbose
CONFIGURE_ARGS+=	--disable-__cxa_atexit
CONFIGURE_ARGS+=	--enable-cxx-flags="-fno-rtti -ffunction-sections"
CONFIGURE_ARGS+=	--enable-target-optspace
CONFIGURE_ARGS+=	--disable-libquadmath
CONFIGURE_ARGS+=	--disable-libssp
CONFIGURE_ARGS+=	--without-long-double-128
CONFIGURE_ARGS+=	--enable-gcov-custom-rtio

post-extract:
	${CP} -r ${WRKDIR}/crosstool-NG*/overlays/xtensa_esp32/gcc/. ${WRKSRC}/.
	${LN} -s ${WRKDIR}/newlib-*/newlib ${WRKSRC}/newlib
	${LN} -s ${WRKDIR}/newlib-*/libgloss ${WRKSRC}/libgloss

pre-configure:
	${RUN} cd ${WRKSRC} && ${MKDIR} ${OBJDIR}

.include "../../devel/gmp/buildlink3.mk"
.include "../../math/mpfr/buildlink3.mk"
.include "../../math/mpcomplex/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
