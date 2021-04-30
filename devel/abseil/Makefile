# $NetBSD: Makefile,v 1.8 2021/04/30 10:32:17 adam Exp $

DISTNAME=	abseil-20210324.1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=abseil/}
GITHUB_PROJECT=	abseil-cpp
GITHUB_TAG=	${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/abseil/abseil-cpp
COMMENT=	C++ Common Libraries
LICENSE=	apache-2.0

USE_CMAKE=	yes
USE_LANGUAGES=	c++11
CMAKE_ARGS+=	-DBUILD_SHARED_LIBS=ON

.include "../../mk/atomic64.mk"
.include "../../mk/bsd.pkg.mk"
