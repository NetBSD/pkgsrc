# $NetBSD: Makefile,v 1.1 2025/02/10 10:49:53 adam Exp $

DISTNAME=	ade-0.1.2e
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=opencv/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/opencv/ade
COMMENT=	Graph construction, manipulation, and processing framework
LICENSE=	apache-2.0

USE_CXX_FEATURES=	c++11
USE_LANGUAGES=		c c++

.include "../../devel/cmake/build.mk"
.include "../../mk/bsd.pkg.mk"
