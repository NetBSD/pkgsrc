# $NetBSD: Makefile,v 1.82 2026/01/07 08:47:08 wiz Exp $

DISTNAME=	palapeli-${KAPPSVER}
PKGREVISION=	1
CATEGORIES=	games

HOMEPAGE=	https://kde.org/applications/games/palapeli/
COMMENT=	Jigsaw puzzle game based on KDE technology
LICENSE=	gnu-lgpl-v2 AND gnu-gpl-v2 AND gnu-fdl-v1.2

.include "../../meta-pkgs/kde/applications.mk"

TOOL_DEPENDS+=	kf6-kdoctools>=6.18.0:../../devel/kf6-kdoctools

USE_TOOLS+=	msgmerge

SUBST_CLASSES+=		xdg
SUBST_STAGE.xdg=	pre-configure
SUBST_MESSAGE.xdg=	Install via examples dir.
SUBST_FILES.xdg=	puzzles/CMakeLists.txt
SUBST_SED.xdg=		-e 's:{KDE_INSTALL_CONFDIR}:{KDE_INSTALL_XDG_EX_DIR}:'

MAKE_DIRS+=	${PKG_SYSCONFDIR}/xdg
CONF_FILES+=	${PREFIX}/share/examples/kde-xdg/palapeli-collectionrc \
		${PKG_SYSCONFDIR}/xdg/palapeli-collectionrc

.include "../../devel/kf6-kio/buildlink3.mk"
.include "../../games/libkdegames/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
