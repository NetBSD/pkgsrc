# $NetBSD: Makefile,v 1.11 2019/07/01 14:01:27 nia Exp $

DISTNAME=	teeworlds-0.7.3.1-src
PKGNAME=	${DISTNAME:S/-src//}
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_GITHUB:=teeworlds/}
GITHUB_RELEASE=	${PKGVERSION_NOREV}

MAINTAINER=	fstd.lkml@gmail.com
HOMEPAGE=	https://www.teeworlds.com/
COMMENT=	Fast-paced retro multiplayer shooter
LICENSE=	zlib AND 2-clause-bsd AND modified-bsd AND cc-by-sa-v3.0

USE_LANGUAGES=	c c++03
USE_CMAKE=	yes
USE_TOOLS+=	pkg-config

INSTALLATION_DIRS+=	share/appdata
INSTALLATION_DIRS+=	share/applications
.for size in 256 128 48 32 24 16
INSTALLATION_DIRS+=	share/icons/hicolor/${size}x${size}/apps
.endfor

TOOL_DEPENDS+=	ImageMagick-[0-9]*:../../graphics/ImageMagick

pre-configure:
	convert ${WRKSRC}/other/icons/teeworlds.ico[0] ${WRKDIR}/teeworlds-256.png
	convert ${WRKSRC}/other/icons/teeworlds.ico[1] ${WRKDIR}/teeworlds-128.png
	convert ${WRKSRC}/other/icons/teeworlds.ico[2] ${WRKDIR}/teeworlds-48.png
	convert ${WRKSRC}/other/icons/teeworlds.ico[3] ${WRKDIR}/teeworlds-32.png
	convert ${WRKSRC}/other/icons/teeworlds.ico[4] ${WRKDIR}/teeworlds-24.png
	convert ${WRKSRC}/other/icons/teeworlds.ico[5] ${WRKDIR}/teeworlds-16.png

post-install:
	${INSTALL_DATA} ${WRKSRC}/other/teeworlds.desktop ${DESTDIR}${PREFIX}/share/applications
	${INSTALL_DATA} ${WRKSRC}/other/teeworlds.appdata.xml ${DESTDIR}${PREFIX}/share/appdata
.for size in 256 128 48 32 24 16
	${INSTALL_DATA} ${WRKDIR}/teeworlds-${size}.png \
	    ${DESTDIR}${PREFIX}/share/icons/hicolor/${size}x${size}/apps/teeworlds.png
.endfor

.include "../../audio/wavpack/buildlink3.mk"
.include "../../devel/SDL2/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/glu/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
