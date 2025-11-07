# $NetBSD: Makefile,v 1.1 2025/11/07 09:18:43 adam Exp $

DISTNAME=	gcem-1.18.0
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_GITHUB:=kthohr/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/kthohr/gcem
COMMENT=	Templated C++ library for computation of mathematical functions
LICENSE=	apache-2.0

USE_CXX_FEATURES=	c++11
USE_LANGUAGES=		c c++

CMAKE_CONFIGURE_ARGS+=	-DCMAKE_POLICY_VERSION_MINIMUM=3.5

.include "../../devel/cmake/build.mk"
.include "../../mk/bsd.pkg.mk"
