# $NetBSD: Makefile,v 1.9 2020/11/24 18:10:03 nia Exp $
#

DISTNAME=	powder118_src
PKGNAME=	${DISTNAME:S/_src//:S/powder/powder-/}
CATEGORIES=	games
MASTER_SITES=	http://www.zincland.com/powder/release/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.zincland.com/powder/index.php?pagename=about
COMMENT=	Multiplatform roguelike game with graphics
LICENSE=	powder-license

USE_LANGUAGES=	c c++03
USE_TOOLS+=	bash gmake

INSTALLATION_DIRS=	bin share/doc/powder
INSTALLATION_DIRS+=	share/applications
INSTALLATION_DIRS+=	share/icons/hicolor/48x48/apps
INSTALLATION_DIRS+=	${PKGMANDIR}/man6

REPLACE_BASH=	buildall.sh gfx/rebuild.sh rooms/buildrooms.bash

do-build:
	cd ${WRKSRC} && ${MAKE_ENV} ./buildall.sh

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/powder ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${FILESDIR}/powder.desktop \
		${DESTDIR}${PREFIX}/share/applications
	${INSTALL_DATA} ${FILESDIR}/powder.6 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man6
	${INSTALL_DATA} ${WRKSRC}/port/android/powder/res/drawable-mdpi/ic_launcher.png \
		${DESTDIR}${PREFIX}/share/icons/hicolor/48x48/apps/powder.png
	${INSTALL_DATA} ${WRKSRC}/CREDITS.TXT \
		${DESTDIR}${PREFIX}/share/doc/powder
	${INSTALL_DATA} ${WRKSRC}/LICENSE.TXT \
		${DESTDIR}${PREFIX}/share/doc/powder
	${INSTALL_DATA} ${WRKSRC}/README.TXT \
		${DESTDIR}${PREFIX}/share/doc/powder

.include "../../devel/SDL/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
