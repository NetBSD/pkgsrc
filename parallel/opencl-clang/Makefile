# $NetBSD: Makefile,v 1.16 2024/05/29 16:34:07 adam Exp $

DISTNAME=	opencl-clang-17.0.0
PKGREVISION=	1
CATEGORIES=	parallel
MASTER_SITES=	${MASTER_SITE_GITHUB:=intel/}
GITHUB_PROJECT=	opencl-clang	# do not remove this, it breaks cwrappers
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/intel/opencl-clang
COMMENT=	OpenCL-oriented wrapper library around clang
LICENSE=	modified-bsd

USE_CXX_FEATURES=	c++17
FORCE_CXX_STD=		c++17
USE_LANGUAGES=		c c++

BUILDLINK_TRANSFORM.Darwin+=	rm:-Wl,--no-undefined
BUILDLINK_TRANSFORM.Darwin+=	rm:-Wl,-Bsymbolic
BUILDLINK_TRANSFORM.Darwin+=	rm:-Wl,--version-script=${WRKSRC}/opencl_clang.map
BUILDLINK_TRANSFORM.SunOS+=	rm:-Wl,--version-script=${WRKSRC}/opencl_clang.map

.include "../../devel/cmake/build.mk"
.include "../../parallel/spirv-llvm-translator/buildlink3.mk"
.include "../../lang/clang/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
