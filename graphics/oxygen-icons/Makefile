# $NetBSD: Makefile,v 1.48 2024/02/06 11:24:07 markd Exp $

DISTNAME=	oxygen-icons-5.114.0
CATEGORIES=	graphics kde
MASTER_SITES=	${MASTER_SITE_KDE:=frameworks/${PKGVERSION_NOREV:R}/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	markd@NetBSD.org
HOMEPAGE=	http://www.oxygen-icons.org/
COMMENT=	Oxygen icon set for the KDE integrated X11 desktop
LICENSE=	gnu-lgpl-v3

TOOL_DEPENDS+=		extra-cmake-modules>=5.98.0:../../devel/extra-cmake-modules

USE_LANGUAGES=	c c++

# Why a collection of images requires a C++17 compiler is anyone's guess,
# but this is a hard requirement from the KDE cmake infrastructure.
USE_CXX_FEATURES+=	c++17

CMAKE_ARGS+=	-DKF_IGNORE_PLATFORM_CHECK=true

.include "../../devel/cmake/build.mk"
.include "../../mk/bsd.pkg.mk"
