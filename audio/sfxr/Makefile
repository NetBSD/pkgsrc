# $NetBSD: Makefile,v 1.22 2014/05/05 00:47:38 ryoon Exp $
#

DISTNAME=	sfxr-sdl-1.2.1
PKGNAME=	${DISTNAME:S/-sdl//}
PKGREVISION=	11
CATEGORIES=	audio
MASTER_SITES=	http://www.drpetter.se/files/

MAINTAINER=	wiz@NetBSD.org
HOMEPAGE=	http://www.drpetter.se/project_sfxr.html
COMMENT=	Sound generator for 8-bit game sounds
LICENSE=	mit

USE_LANGUAGES=	c++
USE_TOOLS+=	gmake pkg-config
BUILD_TARGET=	sfxr

SUBST_CLASSES+=		prefix
SUBST_SED.prefix=	-e "s,/usr,${PREFIX},g"
SUBST_FILES.prefix=	sdlkit.h main.cpp Makefile
SUBST_STAGE.prefix=	pre-build
SUBST_MESSAGE.prefix=	Fixing installation path.

INSTALLATION_DIRS=	bin share/sfxr share/applications share/doc/sfxr
INSTALLATION_DIRS+=	share/icons/hicolor/48x48/apps

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/sfxr ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/*.tga ${DESTDIR}${PREFIX}/share/sfxr
	${INSTALL_DATA} ${WRKSRC}/*.bmp ${DESTDIR}${PREFIX}/share/sfxr
	${INSTALL_DATA} ${WRKSRC}/sfxr.png ${DESTDIR}${PREFIX}/share/icons/hicolor/48x48/apps
	${INSTALL_DATA} ${WRKSRC}/sfxr.desktop ${DESTDIR}${PREFIX}/share/applications
	${INSTALL_DATA} ${WRKSRC}/readme.txt ${DESTDIR}${PREFIX}/share/doc/sfxr

.include "../../devel/SDL/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
