# $NetBSD: Makefile,v 1.1 2024/02/11 21:45:44 ryoon Exp $

DISTNAME=	zxcvbn-c-2.5
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_GITHUB:=tsyrogit/}
GITHUB_PROJECT=	zxcvbn-c
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://github.com/tsyrogit/zxcvbn-c/
COMMENT=	Password strength estimator
LICENSE=	mit

USE_LANGUAGES=		c c++
USE_CXX_FEATURES=	c++11

USE_TOOLS+=	gmake

MAKE_FILE=	makefile

.include "../../mk/bsd.pkg.mk"
