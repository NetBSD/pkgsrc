# $NetBSD: Makefile,v 1.4 2023/12/13 11:44:26 nros Exp $

DISTNAME=	GSL-4.0.0
PKGNAME=	c++${DISTNAME:tl}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=Microsoft/}
GITHUB_PROJECT=	GSL
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	nros@NetBSD.org
HOMEPAGE=	https://github.com/Microsoft/GSL
COMMENT=	C++ Core Guidelines support library
LICENSE=	mit

NO_BUILD=	yes
USE_LANGUAGES+=	c++

USE_CXX_FEATURES+=	c++14

CMAKE_CONFIGURE_ARGS+=	-DGSL_TEST=False

.include "../../devel/cmake/build.mk"

.include "../../mk/bsd.pkg.mk"
