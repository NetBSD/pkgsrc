# $NetBSD: Makefile,v 1.89 2024/05/29 16:34:27 adam Exp $

DISTNAME=	krusader-2.8.0
PKGREVISION=	6
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_KDE:=krusader/${PKGVERSION_NOREV}/}
LICENSE=	gnu-gpl-v2

MAINTAINER=	kikadf.01@gmail.com
HOMEPAGE=	https://krusader.org/
COMMENT=	Advanced twin-panel (commander-style) file-manager for KDE Plasma

.include "../../meta-pkgs/kde/applications.mk"

SUBST_CLASSES+=		xdg
SUBST_STAGE.xdg=	pre-configure
SUBST_MESSAGE.xdg=	Install via examples dir.
SUBST_FILES.xdg=	plugins/iso/CMakeLists.txt
SUBST_SED.xdg=		-e 's:{KDE_INSTALL_CONFDIR}:{KDE_INSTALL_XDG_EX_DIR}:'

MAKE_DIRS+=	${PKG_SYSCONFBASE}/xdg
CONF_FILES+=	${PREFIX}/share/examples/kde-xdg/kio_isorc \
		${PKG_SYSCONFBASE}/xdg/kio_isorc
BUILD_DEFS+=	PKG_SYSCONFBASE

DEPENDS+=	oxygen-icons-[0-9]*:../../graphics/oxygen-icons

.include "../../devel/kparts/buildlink3.mk"
.include "../../graphics/glu/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/plasma-framework/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
