# $NetBSD: Makefile,v 1.12 2026/03/11 11:05:37 adam Exp $

DISTNAME=	fast_float-8.2.4
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
