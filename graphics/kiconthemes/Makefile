# $NetBSD: Makefile,v 1.20 2019/04/25 20:53:51 markd Exp $

DISTNAME=	kiconthemes-${KF5VER}
CATEGORIES=	graphics

HOMEPAGE=	https://community.kde.org/Frameworks
COMMENT=	Support for icon themes
LICENSE=	gnu-lgpl-v2.1

.include "../../meta-pkgs/kde/kf5.mk"

USE_TOOLS+=	msgmerge

SUBST_CLASSES+=		xdg
SUBST_STAGE.xdg=	pre-configure
SUBST_MESSAGE.xdg=	Install via examples dir.
SUBST_FILES.xdg=	CMakeLists.txt
SUBST_SED.xdg=		-e 's:{KDE_INSTALL_CONFDIR}:{KDE_INSTALL_XDG_EX_DIR}:'

MAKE_DIRS+=	${PKG_SYSCONFDIR}/xdg
CONF_FILES+=	${PREFIX}/share/examples/kde-xdg/kiconthemes.categories \
		${PKG_SYSCONFDIR}/xdg/kiconthemes.categories

.include "../../lang/python/tool.mk"
.include "../../archivers/karchive/buildlink3.mk"
.include "../../x11/kconfigwidgets/buildlink3.mk"
.include "../../x11/kitemviews/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../x11/qt5-qtsvg/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
