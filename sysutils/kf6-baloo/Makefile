# $NetBSD: Makefile,v 1.1 2024/05/26 12:52:34 markd Exp $

DISTNAME=	baloo-${KF6VER}
CATEGORIES=	sysutils

HOMEPAGE=	https://community.kde.org/Frameworks
COMMENT=	Framework for searching and managing metadata
LICENSE=	gnu-gpl-v2 AND gnu-lgpl-v2.1

.include "../../meta-pkgs/kde/kf6.mk"

TOOL_DEPENDS+=	kf6-kdoctools>=${KF6VER}:../../devel/kf6-kdoctools

USE_TOOLS+=	msgmerge pkg-config

SUBST_CLASSES+=		xdg
SUBST_STAGE.xdg=	pre-configure
SUBST_MESSAGE.xdg=	Install via examples dir.
SUBST_FILES.xdg=	src/file/CMakeLists.txt
SUBST_SED.xdg=		-e 's:{KDE_INSTALL_AUTOSTARTDIR}:{KDE_INSTALL_AUTOSTARTEXDIR}:'

MAKE_DIRS+=	${PKG_SYSCONFDIR}/xdg/autostart
CONF_FILES+=	${PREFIX}/share/examples/kde-xdg/autostart/baloo_file.desktop \
		${PKG_SYSCONFDIR}/xdg/autostart/baloo_file.desktop

PKGCONFIG_OVERRIDE+=		_KDE_build/src/lib/KF6Baloo.pc
PKGCONFIG_OVERRIDE_STAGE=	post-build

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} != "Linux" && ${OPSYS} != "SunOS"
.include "../../devel/libinotify/buildlink3.mk"
.endif
.include "../../databases/lmdb/buildlink3.mk"
.include "../../devel/kf6-kconfig/buildlink3.mk"
.include "../../devel/kf6-kcoreaddons/buildlink3.mk"
.include "../../devel/kf6-kcrash/buildlink3.mk"
.include "../../devel/kf6-ki18n/buildlink3.mk"
.include "../../devel/kf6-kidletime/buildlink3.mk"
.include "../../devel/kf6-kio/buildlink3.mk"
.include "../../sysutils/kf6-kdbusaddons/buildlink3.mk"
.include "../../sysutils/kf6-kfilemetadata/buildlink3.mk"
.include "../../sysutils/kf6-solid/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
