# $NetBSD: Makefile,v 1.45 2023/07/10 07:59:49 nia Exp $

DISTNAME=	oxygen-icons5-5.98.0
PKGNAME=	${DISTNAME:S/5//}
CATEGORIES=	graphics kde
MASTER_SITES=	${MASTER_SITE_KDE:=frameworks/${PKGVERSION_NOREV:R}/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	markd@NetBSD.org
HOMEPAGE=	http://www.oxygen-icons.org/
COMMENT=	Oxygen icon set for the KDE integrated X11 desktop
LICENSE=	gnu-lgpl-v3

TOOL_DEPENDS+=		extra-cmake-modules>=5.98.0:../../devel/extra-cmake-modules

# Why a collection of images requires a C++17 compiler is anyone's guess,
# but this is a hard requirement from the KDE cmake infrastructure.
USE_LANGUAGES=	c c++
GCC_REQD+=	7

CMAKE_ARGS+=	-DKF_IGNORE_PLATFORM_CHECK=true

.include "../../devel/cmake/build.mk"
.include "../../mk/bsd.pkg.mk"
