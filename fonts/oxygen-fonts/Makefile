# $NetBSD: Makefile,v 1.2 2016/05/09 10:36:55 markd Exp $

DISTNAME=	oxygen-fonts-${PLASMAVER}
CATEGORIES=	fonts kde
MASTER_SITES=	${MASTER_SITE_KDE:=plasma/${PLASMAVER}/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	markd@NetBSD.org
HOMEPAGE=	http://projects.kde.org/projects/oxygen-fonts
COMMENT=	The Oxygen font family
LICENSE=	gnu-gpl-v3 AND ofl-v1.1

PLASMAVER=	5.4.3
BUILD_DEPENDS+= extra-cmake-modules>=5.19.0:../../devel/extra-cmake-modules
BUILD_DEPENDS+= fontforge-[0-9]*:../../fonts/fontforge

USE_CMAKE=	yes
USE_LANGUAGES=	c c++
CMAKE_ARG_PATH=	..
CONFIGURE_DIRS=	_KDE_build

CMAKE_ARGS+=	-DOXYGEN_FONT_INSTALL_DIR=${PREFIX}/share/fonts/X11/TTF

pre-configure:
	${MKDIR} ${WRKSRC}/_KDE_build

.include "../../mk/bsd.pkg.mk"
