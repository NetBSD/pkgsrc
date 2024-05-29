# $NetBSD: Makefile,v 1.8 2024/05/29 16:34:28 adam Exp $

DISTNAME=	milou-${PLASMAVER}
PKGREVISION=	2
CATEGORIES=	sysutils

HOMEPAGE=	https://www.kde.org/workspaces/plasmadesktop/
COMMENT=	Dedicated search application built on top of Baloo
LICENSE=	gnu-gpl-v2 AND gnu-lgpl-v2.1

.include "../../meta-pkgs/kde/plasma5.mk"

TOOL_DEPENDS+=	kdoctools>=5.19.0:../../devel/kdoctools

USE_TOOLS+=	msgmerge

# generation of module.moc fails when ${PREFIX}/include in the moc include path
SUBST_CLASSES+=		fix-moc
SUBST_STAGE.fix-moc=	post-configure
SUBST_MESSAGE.fix-moc=	Cleaning up MOC includes
SUBST_FILES.fix-moc=	_KDE_build/lib/previews/CMakeFiles/miloutextplugin_autogen.dir/AutogenInfo.json
SUBST_NOOP_OK.fix-moc=	yes
SUBST_SED.fix-moc=	-e 's;"${PREFIX}/include",;;g'

.include "../../devel/kitemmodels/buildlink3.mk"
.include "../../devel/krunner/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
