# $NetBSD: Makefile,v 1.41 2022/04/25 03:22:25 markd Exp $

DISTNAME=	oxygen-icons5-5.93.0
PKGNAME=	${DISTNAME:S/5//}
CATEGORIES=	graphics kde
MASTER_SITES=	${MASTER_SITE_KDE:=frameworks/${PKGVERSION_NOREV:R}/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	markd@NetBSD.org
HOMEPAGE=	http://www.oxygen-icons.org/
COMMENT=	Oxygen icon set for the KDE integrated X11 desktop
LICENSE=	gnu-lgpl-v3

BUILD_DEPENDS+=		extra-cmake-modules>=5.93.0:../../devel/extra-cmake-modules
TOOLS_DEPENDS.cmake=	cmake>=3.0:../../devel/cmake

USE_CMAKE=	yes
USE_LANGUAGES=	c c++
CMAKE_ARG_PATH=	..
CONFIGURE_DIRS=	_KDE_build

CMAKE_ARGS+=	-DKF_IGNORE_PLATFORM_CHECK=true

pre-configure:
	${MKDIR} ${WRKSRC}/_KDE_build

.include "../../mk/bsd.pkg.mk"
