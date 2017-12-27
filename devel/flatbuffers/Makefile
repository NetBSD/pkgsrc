# $NetBSD: Makefile,v 1.2 2017/12/27 20:47:00 he Exp $

DISTNAME=	flatbuffers-1.8.0
CATEGORIES=	devel
PKGREVISION=	1
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
