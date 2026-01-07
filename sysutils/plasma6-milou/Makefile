# $NetBSD: Makefile,v 1.2 2026/01/07 08:48:56 wiz Exp $

DISTNAME=	milou-${PLASMAVER}
PKGREVISION=	1
CATEGORIES=	sysutils

HOMEPAGE=	https://www.kde.org/workspaces/plasmadesktop/
COMMENT=	Dedicated search application built on top of Baloo
LICENSE=	gnu-gpl-v2 AND gnu-lgpl-v2.1

.include "../../meta-pkgs/kde/plasma6.mk"

TOOL_DEPENDS+=	kf6-kdoctools>=6.18.0:../../devel/kf6-kdoctools

USE_TOOLS+=	msgmerge

# generation of module.moc fails when ${PREFIX}/include in the moc include path
SUBST_CLASSES+=		fix-moc
SUBST_STAGE.fix-moc=	post-configure
SUBST_MESSAGE.fix-moc=	Cleaning up MOC includes
SUBST_FILES.fix-moc=	_KDE_build/lib/previews/CMakeFiles/miloutextplugin_autogen.dir/AutogenInfo.json
SUBST_NOOP_OK.fix-moc=	yes
SUBST_SED.fix-moc=	-e 's;"${PREFIX}/include",;;g'

.include "../../devel/kf6-kitemmodels/buildlink3.mk"
.include "../../devel/kf6-krunner/buildlink3.mk"
.include "../../x11/plasma6-libplasma/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
