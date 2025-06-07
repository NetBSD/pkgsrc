# $NetBSD: Makefile,v 1.2 2025/06/07 12:10:58 wiz Exp $

DISTNAME=	draco-1.5.7
CATEGORIES=	geography
MASTER_SITES=	${MASTER_SITE_GITHUB:=google/}
GITHUB_TAG=	${PKGVERSION_NOREV}

MAINTAINER=	gdt@NetBSD.org
HOMEPAGE=	https://github.com/google/draco/
COMMENT=	Point cloud (geospatial) compression library
LICENSE=	apache-2.0	# CLA for inbound

USE_LANGUAGES=	c c++

# cmake looks for python, but doesn't seem to use it

.include "../../devel/cmake/build.mk"
.include "../../mk/bsd.pkg.mk"
