# $NetBSD: Makefile,v 1.31 2020/06/02 08:22:38 adam Exp $

DISTNAME=	kservice-${KF5VER}
PKGREVISION=	4
CATEGORIES=	devel

HOMEPAGE=	https://community.kde.org/Frameworks
COMMENT=	Advanced plugin and service introspection
LICENSE=	gnu-gpl-v2 AND gnu-gpl-v3 AND gnu-lgpl-v2.1

.include "../../meta-pkgs/kde/kf5.mk"

BUILD_DEPENDS+=	kdoctools>=${KF5VER}:../../devel/kdoctools

USE_TOOLS+=	bison flex msgmerge

SUBST_CLASSES+=		xdg
SUBST_STAGE.xdg=	pre-configure
SUBST_MESSAGE.xdg=	Install via examples dir.
SUBST_FILES.xdg=	src/CMakeLists.txt
SUBST_SED.xdg=		-e 's:{KDE_INSTALL_SYSCONFDIR}/xdg/menus:{KDE_INSTALL_DATAROOTDIR}/examples/kservice:'

MAKE_DIRS+=	${PKG_SYSCONFDIR}/xdg/menus
CONF_FILES+=	${PREFIX}/share/examples/kservice/applications.menu \
		${PKG_SYSCONFDIR}/xdg/menus/applications.menu

.include "../../lang/python/tool.mk"
.include "../../devel/kconfig/buildlink3.mk"
.include "../../devel/kcrash/buildlink3.mk"
.include "../../devel/ki18n/buildlink3.mk"
.include "../../sysutils/kdbusaddons/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
