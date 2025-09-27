# $NetBSD: Makefile,v 1.28 2025/09/27 09:57:37 wiz Exp $

DISTNAME=	lucene++-3.0.9
PKGREVISION=	3
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
CMAKE_CONFIGURE_ARGS+=	-DCMAKE_POLICY_VERSION_MINIMUM=3.5

.include "../../devel/boost-libs/buildlink3.mk"
.include "../../devel/cmake/build.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
