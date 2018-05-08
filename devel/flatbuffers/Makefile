# $NetBSD: Makefile,v 1.3 2018/05/08 16:44:15 minskim Exp $

DISTNAME=	flatbuffers-1.9.0
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=google/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://google.github.io/flatbuffers/
COMMENT=	Memory efficient serialization library
LICENSE=	apache-2.0

USE_CMAKE=	yes
USE_LANGUAGES=	c c++11

CMAKE_ARGS+=	-DCMAKE_BUILD_TYPE=Release
CMAKE_ARGS+=	-DFLATBUFFERS_BUILD_SHAREDLIB=ON

.include "../../mk/bsd.pkg.mk"
