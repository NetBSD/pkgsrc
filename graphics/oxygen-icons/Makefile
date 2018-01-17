# $NetBSD: Makefile,v 1.29 2018/01/17 20:03:37 markd Exp $

DISTNAME=	oxygen-icons5-5.41.0
PKGNAME=	${DISTNAME:S/5//}
CATEGORIES=	graphics kde
MASTER_SITES=	${MASTER_SITE_KDE:=frameworks/5.41/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	markd@NetBSD.org
HOMEPAGE=	http://www.oxygen-icons.org/
COMMENT=	Oxygen icon set for the KDE integrated X11 desktop
LICENSE=	gnu-lgpl-v3

BUILD_DEPENDS+= extra-cmake-modules>=5.41.0:../../devel/extra-cmake-modules
TOOLS_DEPENDS.cmake= cmake>=3.0:../../devel/cmake

USE_CMAKE=	yes
USE_LANGUAGES=	c c++
CMAKE_ARG_PATH=	..
CONFIGURE_DIRS=	_KDE_build

pre-configure:
	${MKDIR} ${WRKSRC}/_KDE_build

.include "../../mk/bsd.pkg.mk"
