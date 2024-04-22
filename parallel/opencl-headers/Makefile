# $NetBSD: Makefile,v 1.2 2024/04/22 10:43:00 adam Exp $

DISTNAME=	opencl-headers-2023.12.14
CATEGORIES=	parallel
MASTER_SITES=	${MASTER_SITE_GITHUB:=KhronosGroup/}
GITHUB_PROJECT=	OpenCL-Headers
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/KhronosGroup/OpenCL-Headers
COMMENT=	C language headers for the OpenCL API
LICENSE=	apache-2.0

USE_LANGUAGES=	c c++

.include "../../devel/cmake/build.mk"
.include "../../mk/bsd.pkg.mk"
