# $NetBSD: Makefile,v 1.2 2026/01/07 08:48:56 wiz Exp $

DISTNAME=	kde-cli-tools-${PLASMAVER}
PKGREVISION=	1
CATEGORIES=	sysutils

HOMEPAGE=	https://www.kde.org/workspaces/plasmadesktop/
COMMENT=	Tools based on KDE Frameworks to better interact with the system
LICENSE=	gnu-gpl-v2 AND gnu-lgpl-v2.1

.include "../../meta-pkgs/kde/plasma6.mk"

TOOL_DEPENDS+=	kf6-kdoctools>=6.18.0:../../devel/kf6-kdoctools

USE_TOOLS+=	msgmerge pkg-config

SUBST_CLASSES+=		fix-moc
SUBST_STAGE.fix-moc=	post-configure
SUBST_MESSAGE.fix-moc=	Cleaning up MOC includes
SUBST_FILES.fix-moc=	_KDE_build/*/CMakeFiles/*_autogen.dir/AutogenInfo.json
SUBST_FILES.fix-moc+=	_KDE_build/*/*/CMakeFiles/*_autogen.dir/AutogenInfo.json
SUBST_NOOP_OK.fix-moc=	yes
SUBST_SED.fix-moc=	-e 's;"${PREFIX}/include",;;g'

.include "../../devel/kf6-kcmutils/buildlink3.mk"
.include "../../devel/kf6-kconfig/buildlink3.mk"
.include "../../devel/kf6-kcoreaddons/buildlink3.mk"
.include "../../devel/kf6-ki18n/buildlink3.mk"
.include "../../devel/kf6-kio/buildlink3.mk"
.include "../../devel/kf6-kparts/buildlink3.mk"
.include "../../devel/kf6-kservice/buildlink3.mk"
.include "../../graphics/kf6-kiconthemes/buildlink3.mk"
.include "../../graphics/qt6-qtsvg/buildlink3.mk"
.include "../../security/kf6-kdesu/buildlink3.mk"
.include "../../x11/kf6-kwindowsystem/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
