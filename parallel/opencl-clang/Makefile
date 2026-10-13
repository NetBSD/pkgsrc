# $NetBSD: Makefile,v 1.29 2026/10/13 08:08:46 adam Exp $

DISTNAME=	opencl-clang-22.1.4
CATEGORIES=	parallel
MASTER_SITES=	${MASTER_SITE_GITHUB:=intel/}
GITHUB_PROJECT=	opencl-clang
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/intel/opencl-clang
COMMENT=	OpenCL-oriented wrapper library around clang
LICENSE=	modified-bsd

USE_CXX_FEATURES=	c++17
FORCE_CXX_STD=		c++17
USE_LANGUAGES=		c c++

CFLAGS+=	-I${PREFIX}/include/LLVMSPIRVLib

BUILDLINK_TRANSFORM.Darwin+=	rm:-Wl,--no-undefined
BUILDLINK_TRANSFORM.Darwin+=	rm:-Wl,-Bsymbolic
BUILDLINK_TRANSFORM.Darwin+=	rm:-Wl,--version-script=${WRKSRC}/opencl_clang.map
BUILDLINK_TRANSFORM.SunOS+=	rm:-Wl,--version-script=${WRKSRC}/opencl_clang.map

.include "../../devel/cmake/build.mk"
.include "../../lang/clang/buildlink3.mk"
.include "../../parallel/spirv-llvm-translator/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
