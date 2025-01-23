# $NetBSD: Makefile,v 1.50 2025/01/23 23:27:26 riastradh Exp $

DISTNAME=	oxygen-icons-5.114.0
CATEGORIES=	graphics kde
MASTER_SITES=	${MASTER_SITE_KDE:=frameworks/${PKGVERSION_NOREV:R}/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	markd@NetBSD.org
HOMEPAGE=	http://www.oxygen-icons.org/
COMMENT=	Oxygen icon set for the KDE integrated X11 desktop
LICENSE=	gnu-lgpl-v3

USE_LANGUAGES=	c c++

# Why a collection of images requires a C++17 compiler is anyone's guess,
# but this is a hard requirement from the KDE cmake infrastructure.
USE_CXX_FEATURES+=	c++17

CMAKE_CONFIGURE_ARGS+=	-DKF_IGNORE_PLATFORM_CHECK=true

.include "../../devel/cmake/build.mk"

BUILDLINK_API_DEPENDS.extra-cmake-modules+=	extra-cmake-modules>=5.98.0
.include "../../devel/extra-cmake-modules/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
