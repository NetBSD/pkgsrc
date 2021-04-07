# $NetBSD: Makefile,v 1.45 2021/04/07 12:28:21 markd Exp $

DISTNAME=	kpat-${KAPPSVER}
PKGREVISION=	6
CATEGORIES=	games

HOMEPAGE=	https://kde.org/applications/games/kpat/
COMMENT=	Multiplicity of different solitaire games
LICENSE=	gnu-gpl-v2 AND gnu-fdl-v1.2

KAPPSVER=	20.04.1
.include "../../meta-pkgs/kde/applications.mk"

BUILD_DEPENDS+=	kdoctools>=5.19.0:../../devel/kdoctools

USE_TOOLS+=	msgmerge pkg-config

SUBST_CLASSES+=		xdg
SUBST_STAGE.xdg=	pre-configure
SUBST_MESSAGE.xdg=	Install via examples dir.
SUBST_FILES.xdg=	themes/CMakeLists.txt
SUBST_FILES.xdg+=	libkcardgame/CMakeLists.txt
SUBST_SED.xdg=		-e 's:{KDE_INSTALL_CONFDIR}:{KDE_INSTALL_XDG_EX_DIR}:'

MAKE_DIRS+=	${PKG_SYSCONFDIR}/xdg
CONF_FILES+=	${PREFIX}/share/examples/kde-xdg/kcardtheme.knsrc \
		${PKG_SYSCONFDIR}/xdg/kcardtheme.knsrc
CONF_FILES+=	${PREFIX}/share/examples/kde-xdg/kpat.knsrc \
		${PKG_SYSCONFDIR}/xdg/kpat.knsrc

.include "../../games/freecell-solver/buildlink3.mk"
.include "../../games/libkdegames/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
