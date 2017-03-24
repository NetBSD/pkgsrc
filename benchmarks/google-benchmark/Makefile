# $NetBSD: Makefile,v 1.2 2017/03/24 11:41:58 joerg Exp $

DISTNAME=	benchmark-1.1.0
PKGNAME=	google-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	benchmarks
MASTER_SITES=	${MASTER_SITE_GITHUB:=google/}
GITHUB_PROJECT=	benchmark
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://github.com/google/benchmark/
COMMENT=	Microbenchmark support library
LICENSE=	apache-2.0

USE_CMAKE=	yes
USE_LANGUAGES=	c c++

CMAKE_ARGS=	-DCMAKE_BUILD_TYPE=Release

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
