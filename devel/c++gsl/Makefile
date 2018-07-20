# $NetBSD: Makefile,v 1.1 2018/07/20 11:32:25 minskim Exp $

DISTNAME=	GSL-1.0.0
PKGNAME=	c++${DISTNAME:tl}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=Microsoft/}
GITHUB_PROJECT=	GSL
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://github.com/Microsoft/GSL
COMMENT=	C++ Core Guidelines support library
LICENSE=	mit

NO_BUILD=	yes
USE_CMAKE=	yes
USE_LANGUAGES+=	c c++14

CMAKE_ARGS+=	-DGSL_TEST=False

.include "../../mk/bsd.pkg.mk"
