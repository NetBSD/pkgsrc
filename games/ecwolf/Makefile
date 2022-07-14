# $NetBSD: Makefile,v 1.3 2022/07/14 23:46:19 dholland Exp $

DISTNAME=	1.3.3
PKGNAME=	ecwolf-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	games
MASTER_SITES=	https://bitbucket.org/ecwolf/ecwolf/get/
DIST_SUBDIR=	ecwolf

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://bitbucket.org/ecwolf/ecwolf
COMMENT=	Advanced port of Wolfenstein 3D
LICENSE=	gnu-gpl-v2

WRKSRC=		${WRKDIR}/ecwolf-ecwolf-d715e0a2f8d4

USE_CMAKE=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++

# malloc_usable_size()...
LDFLAGS.NetBSD+=	-ljemalloc

SUBST_CLASSES+=		paths
SUBST_STAGE.paths=	pre-configure
SUBST_FILES.paths+=	docs/ecwolf.6
SUBST_FILES.paths+=	src/wl_iwad.cpp
SUBST_SED.paths=	-e 's,/usr/local/share/games/wolf3d,${PREFIX}/share/ecwolf,g'
SUBST_VARS.paths=	PREFIX

INSTALLATION_DIRS+=	${PKGMANDIR}/man6
INSTALLATION_DIRS+=	libexec
INSTALLATION_DIRS+=	share/ecwolf

INSTALLATION_DIRS+=	share/applications
INSTALLATION_DIRS+=	share/icons/hicolor/96x96/apps
INSTALLATION_DIRS+=	share/icons/hicolor/72x72/apps
INSTALLATION_DIRS+=	share/icons/hicolor/48x48/apps
INSTALLATION_DIRS+=	share/icons/hicolor/36x36/apps

pre-configure:
	${SED} -e 's,@PREFIX@,${PREFIX},g' < ${FILESDIR}/ecwolf.sh.in > \
	    ${WRKSRC}/ecwolf.sh

post-install:
	${MV} ${DESTDIR}${PREFIX}/bin/ecwolf \
		${DESTDIR}${PREFIX}/libexec/ecwolf
	${INSTALL_SCRIPT} ${WRKSRC}/ecwolf.sh \
		${DESTDIR}${PREFIX}/bin/ecwolf
	${INSTALL_DATA} ${WRKSRC}/ecwolf.pk3 \
		${DESTDIR}${PREFIX}/share/ecwolf/ecwolf.pk3
	${INSTALL_MAN} ${WRKSRC}/docs/ecwolf.6 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man6/ecwolf.6
	${INSTALL_DATA} ${FILESDIR}/ecwolf.desktop \
		${DESTDIR}${PREFIX}/share/applications/ecwolf.desktop
	${INSTALL_DATA} ${WRKSRC}/android-libs/launcher/res/drawable-ldpi/ic_launcher.png \
		${DESTDIR}${PREFIX}/share/icons/hicolor/36x36/apps/ecwolf.png
	${INSTALL_DATA} ${WRKSRC}/android-libs/launcher/res/drawable-mdpi/ic_launcher.png \
		${DESTDIR}${PREFIX}/share/icons/hicolor/48x48/apps/ecwolf.png
	${INSTALL_DATA} ${WRKSRC}/android-libs/launcher/res/drawable-hdpi/ic_launcher.png \
		${DESTDIR}${PREFIX}/share/icons/hicolor/72x72/apps/ecwolf.png
	${INSTALL_DATA} ${WRKSRC}/android-libs/launcher/res/drawable-xhdpi/ic_launcher.png \
		${DESTDIR}${PREFIX}/share/icons/hicolor/96x96/apps/ecwolf.png

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../audio/SDL_mixer/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../devel/SDL/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
