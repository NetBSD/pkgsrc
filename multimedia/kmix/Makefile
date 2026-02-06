# $NetBSD: Makefile,v 1.118 2026/02/06 10:05:26 wiz Exp $

DISTNAME=	kmix-${KAPPSVER}
PKGREVISION=	3
CATEGORIES=	multimedia

HOMEPAGE=	https://kde.org/applications/multimedia/kmix/
COMMENT=	KDE's soundcard mixer program
LICENSE=	gnu-gpl-v2 AND gnu-fdl-v1.2 AND gnu-lgpl-v2

.include "../../meta-pkgs/kde/applications.mk"

TOOL_DEPENDS+=	kf6-kdoctools>=6.18.0:../../devel/kf6-kdoctools

USE_TOOLS+=	msgmerge pkg-config

CMAKE_CONFIGURE_ARGS+=	-DHAVE_SYS_AUDIOIO_H=false

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
.include "../../devel/kf6-kcrash/buildlink3.mk"
.include "../../devel/kf6-ki18n/buildlink3.mk"
.include "../../devel/kf6-knotifications/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../misc/kf6-kstatusnotifieritem/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../sysutils/kf6-kdbusaddons/buildlink3.mk"
.include "../../sysutils/kf6-solid/buildlink3.mk"
.include "../../x11/kf6-kxmlgui/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
