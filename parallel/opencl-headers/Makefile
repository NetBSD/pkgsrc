# $NetBSD: Makefile,v 1.3 2024/07/06 15:49:09 adam Exp $

DISTNAME=	opencl-headers-2024.05.08
CATEGORIES=	parallel
MASTER_SITES=	${MASTER_SITE_GITHUB:=KhronosGroup/}
GITHUB_PROJECT=	OpenCL-Headers
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/KhronosGroup/OpenCL-Headers
COMMENT=	C language headers for the OpenCL API
LICENSE=	apache-2.0

USE_LANGUAGES=	c c++
TEST_TARGET=	test

.include "../../devel/cmake/build.mk"
.include "../../mk/bsd.pkg.mk"
