# $NetBSD: Makefile,v 1.14 2022/08/11 05:08:37 gutteridge Exp $

DISTNAME=	xonotic-0.8.2
PKGREVISION=	7
CATEGORIES=	games
MASTER_SITES=	https://dl.xonotic.org/
EXTRACT_SUFX=	.zip

MAINTAINER=	charlotte@NetBSD.org
HOMEPAGE=	https://xonotic.org/
COMMENT=	Fast arena-style FPS
LICENSE=	gnu-gpl-v2

USE_TOOLS+=	gmake gsed 7za bash zip
USE_LANGUAGES=	c c++11

# C++11
GCC_REQD+=	4.7

WRKSRC=		${WRKDIR}/Xonotic
BUILD_TARGET=	all-zip-source
INSTALL_TARGET=	install-data-zip-source install-engine-zip-source install-links
INSTALL_ENV+=	LIBDIR=${PREFIX}/share/xonotic

ICON_SIZES=	16 24 32 64 128 256 512

.include "../../mk/bsd.prefs.mk"

.if !empty(MACHINE_PLATFORM:MLinux-*-x86_64)
PLIST_SUBST+=	FAKE_PLATFORM="linux64"
.else
PLIST_SUBST+=	FAKE_PLATFORM="linux32"
.endif

.if ${MACHINE_ARCH} == "i386"
CFLAGS+=	-msse
.endif

INSTALLATION_DIRS+=	share/applications
.for s in ${ICON_SIZES}
INSTALLATION_DIRS+=	share/icons/hicolor/${s}x${s}/apps
.endfor

post-install:
	${INSTALL_DATA} ${FILESDIR}/xonotic.desktop \
	    ${DESTDIR}${PREFIX}/share/applications
.for s in ${ICON_SIZES}
	${INSTALL_DATA}	${WRKSRC}/misc/logos/icons_png/xonotic_${s}.png \
	    ${DESTDIR}${PREFIX}/share/icons/hicolor/${s}x${s}/apps/xonotic.png
.endfor

.if ${OPSYS} == "Linux"
.  include "../../audio/alsa-lib/buildlink3.mk"
.endif
.include "../../devel/SDL2/buildlink3.mk"
.include "../../devel/gmp/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
.include "../../x11/libXxf86vm/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
