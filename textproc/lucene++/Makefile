# $NetBSD: Makefile,v 1.25 2024/10/04 03:49:35 ryoon Exp $

DISTNAME=	lucene++-3.0.9
PKGREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=luceneplusplus/}
GITHUB_PROJECT=	LucenePlusPlus
GITHUB_TAG=	rel_${PKGVERSION_NOREV}

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://github.com/luceneplusplus/LucenePlusPlus/
COMMENT=	C++ port of Lucene text search library
LICENSE=	gnu-lgpl-v3 OR apache-2.0

USE_LANGUAGES=	c c++

CMAKE_CONFIGURE_ARGS+=	-DENABLE_DEMO=OFF
CMAKE_CONFIGURE_ARGS+=	-DENABLE_TEST=OFF

.include "../../devel/boost-libs/buildlink3.mk"
.include "../../devel/cmake/build.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
