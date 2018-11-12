# $NetBSD: Makefile,v 1.24 2018/11/12 03:51:21 ryoon Exp $

DISTNAME=	kxmlrpcclient-${KF5VER}
PKGREVISION=	4
CATEGORIES=	net

HOMEPAGE=	https://community.kde.org/Frameworks
COMMENT=	XML-RPC client library for KDE
LICENSE=	2-clause-bsd AND gnu-lgpl-v2.1

.include "../../meta-pkgs/kde/kf5.mk"

USE_TOOLS+=	msgmerge

SUBST_CLASSES+=		xdg
SUBST_STAGE.xdg=	pre-configure
SUBST_MESSAGE.xdg=	Install via examples dir.
SUBST_FILES.xdg=	CMakeLists.txt
SUBST_SED.xdg=		-e 's:{KDE_INSTALL_CONFDIR}:{KDE_INSTALL_XDG_EX_DIR}:'

MAKE_DIRS+=	${PKG_SYSCONFDIR}/xdg
CONF_FILES+=	${PREFIX}/share/examples/kde-xdg/kxmlrpcclient.categories \
		${PKG_SYSCONFDIR}/xdg/kxmlrpcclient.categories
CONF_FILES+=	${PREFIX}/share/examples/kde-xdg/kxmlrpcclient.renamecategories \
		${PKG_SYSCONFDIR}/xdg/kxmlrpcclient.renamecategories

.include "../../devel/kio/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
