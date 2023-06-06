# $NetBSD: Makefile,v 1.44 2023/06/06 12:41:34 riastradh Exp $

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

USE_LANGUAGES=	c c++

CMAKE_ARGS+=	-DKF_IGNORE_PLATFORM_CHECK=true

.include "../../devel/cmake/build.mk"
.include "../../mk/bsd.pkg.mk"
