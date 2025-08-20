# $NetBSD: Makefile,v 1.5 2025/08/20 11:35:09 wiz Exp $

DISTNAME=	opencl-headers-2024.10.24
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

CMAKE_CONFIGURE_ARGS+=	-DCMAKE_POLICY_VERSION_MINIMUM=3.5

.include "../../devel/cmake/build.mk"
.include "../../mk/bsd.pkg.mk"
