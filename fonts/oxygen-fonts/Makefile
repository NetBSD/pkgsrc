# $NetBSD: Makefile,v 1.7 2024/10/09 02:58:32 markd Exp $

DISTNAME=	oxygen-fonts-${PLASMAVER}
CATEGORIES=	fonts

HOMEPAGE=	https://projects.kde.org/projects/oxygen-fonts
COMMENT=	The Oxygen font family
LICENSE=	gnu-gpl-v3 AND ofl-v1.1

PLASMAVER=	5.4.3
.include "../../meta-pkgs/kde/plasma5.mk"

TOOL_DEPENDS+=	fontforge-[0-9]*:../../fonts/fontforge

CMAKE_CONFIGURE_ARGS+=	-DKDE_INSTALL_USE_QT_SYS_PATHS=OFF
CMAKE_CONFIGURE_ARGS+=	-DOXYGEN_FONT_INSTALL_DIR=${PREFIX}/share/fonts/X11/TTF

.include "../../mk/bsd.pkg.mk"
