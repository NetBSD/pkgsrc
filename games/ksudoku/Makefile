# $NetBSD: Makefile,v 1.81 2026/01/07 08:47:05 wiz Exp $

DISTNAME=	ksudoku-${KAPPSVER}
PKGREVISION=	1
CATEGORIES=	games

HOMEPAGE=	https://kde.org/applications/games/ksudoku/
COMMENT=	Logic-based symbol placement puzzle
LICENSE=	gnu-gpl-v2 AND gnu-fdl-v1.2

.include "../../meta-pkgs/kde/applications.mk"

TOOL_DEPENDS+=	kf6-kdoctools>=6.18.0:../../devel/kf6-kdoctools

USE_TOOLS+=	msgmerge

SUBST_CLASSES+=		xdg
SUBST_STAGE.xdg=	pre-configure
SUBST_MESSAGE.xdg=	Install via examples dir.
SUBST_FILES.xdg=	src/CMakeLists.txt
SUBST_SED.xdg=		-e 's:{KDE_INSTALL_CONFDIR}:{KDE_INSTALL_XDG_EX_DIR}:'

MAKE_DIRS+=	${PKG_SYSCONFDIR}/xdg
CONF_FILES+=	${PREFIX}/share/examples/kde-xdg/ksudokurc \
		${PKG_SYSCONFDIR}/xdg/ksudokurc

.include "../../devel/kf6-kcrash/buildlink3.mk"
.include "../../devel/kf6-kio/buildlink3.mk"
.include "../../games/libkdegames/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
