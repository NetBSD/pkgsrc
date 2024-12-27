# $NetBSD: Makefile,v 1.5 2024/12/27 18:17:15 adam Exp $

DISTNAME=	fast_float-7.0.0
CATEGORIES=	math devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=fastfloat/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/fastfloat/fast_float
COMMENT=	Number parsing library
LICENSE=	mit

USE_CXX_FEATURES=	c++11
USE_LANGUAGES=		c++

.include "../../devel/cmake/build.mk"
.include "../../mk/bsd.pkg.mk"
