# $NetBSD: Makefile,v 1.13 2023/11/08 13:20:39 wiz Exp $

DISTNAME=	opencl-clang-15.0.0
PKGREVISION=	3
CATEGORIES=	parallel
MASTER_SITES=	${MASTER_SITE_GITHUB:=intel/}
GITHUB_PROJECT=	opencl-clang	# do not remove this, it breaks cwrappers
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/intel/opencl-clang
COMMENT=	OpenCL-oriented wrapper library around clang
LICENSE=	modified-bsd

USE_CMAKE=	yes
USE_LANGUAGES=	c c++

# C++14
GCC_REQD+=	7 # sync with llvm/clang

BUILDLINK_TRANSFORM.Darwin+=	rm:-Wl,--version-script=${WRKSRC}/common_clang.map
BUILDLINK_TRANSFORM.SunOS+=	rm:-Wl,--version-script=${WRKSRC}/common_clang.map

.include "../../parallel/spirv-llvm-translator/buildlink3.mk"
.include "../../lang/clang/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
