# $NetBSD: Makefile,v 1.1 2025/06/07 11:45:51 gdt Exp $

VERSION=	1.5.7
DISTNAME=	${VERSION}
PKGNAME=	${GITHUB_PROJECT}-${VERSION}
CATEGORIES=	geography
MASTER_SITES=	${MASTER_SITE_GITHUB:=google/}
GITHUB_PROJECT=	draco
GITHUB_TAG=	refs/tags/${VERSION}
DIST_SUBDIR=	${GITHUB_PROJECT}

MAINTAINER=	gdt@NetBSD.org
HOMEPAGE=	https://github.com/google/draco/
COMMENT=	Point cloud (geospatial) compression library
LICENSE=	apache-2.0	# CLA for inbound

WRKSRC=		${WRKDIR}/draco-1.5.7
USE_LANGUAGES=	c c++

# cmake looks for python, but doesn't seem to use it

.include "../../devel/cmake/build.mk"
.include "../../mk/bsd.pkg.mk"
