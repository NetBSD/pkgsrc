# $NetBSD: Makefile,v 1.79 2022/07/02 16:53:30 ryoon Exp $

DISTNAME=	kmix-${KAPPSVER}
PKGREVISION=	5
CATEGORIES=	multimedia

HOMEPAGE=	https://kde.org/applications/multimedia/kmix/
COMMENT=	KDE's soundcard mixer program
LICENSE=	gnu-gpl-v2 AND gnu-fdl-v1.2 AND gnu-lgpl-v2

.include "../../meta-pkgs/kde/applications.mk"

BUILD_DEPENDS+=	kdoctools>=5.19.0:../../devel/kdoctools
DEPENDS+=	kinit>=5.19.0:../../x11/kinit

USE_TOOLS+=	msgmerge pkg-config

SUBST_CLASSES+=		xdg
SUBST_STAGE.xdg=	pre-configure
SUBST_MESSAGE.xdg=	Install via examples dir.
SUBST_FILES.xdg=	CMakeLists.txt
SUBST_SED.xdg=		-e 's:{KDE_INSTALL_AUTOSTARTDIR}:{KDE_INSTALL_AUTOSTARTEXDIR}:'

MAKE_DIRS+=	${PKG_SYSCONFDIR}/xdg/autostart
CONF_FILES+=	${PREFIX}/share/examples/kde-xdg/autostart/kmix_autostart.desktop \
		${PKG_SYSCONFDIR}/xdg/autostart/kmix_autostart.desktop
CONF_FILES+=	${PREFIX}/share/examples/kde-xdg/autostart/restore_kmix_volumes.desktop \
		${PKG_SYSCONFDIR}/xdg/autostart/restore_kmix_volumes.desktop

# generation of kded.moc fails when ${PREFIX}/include in the moc include path
SUBST_CLASSES+=		fix-moc
SUBST_STAGE.fix-moc=	post-configure
SUBST_MESSAGE.fix-moc=	Cleaning up MOC includes
SUBST_FILES.fix-moc=	_KDE_build/CMakeFiles/kded_kmixd_autogen.dir/AutogenInfo.json
SUBST_FILES.fix-moc+=	_KDE_build/plasma/engine/CMakeFiles/plasma_engine_mixer_autogen.dir/AutogenInfo.json
SUBST_NOOP_OK.fix-moc=	yes
SUBST_SED.fix-moc=	-e 's;"${PREFIX}/include",;;g'

.include "options.mk"

.include "../../audio/alsa-lib/buildlink3.mk"
.include "../../audio/libcanberra/buildlink3.mk"
.include "../../mk/oss.buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/plasma-framework/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
