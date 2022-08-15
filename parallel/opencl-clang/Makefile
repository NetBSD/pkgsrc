# $NetBSD: Makefile,v 1.7 2022/08/15 20:45:21 tnn Exp $

DISTNAME=	opencl-clang-14.0.0
CATEGORIES=	parallel
MASTER_SITES=	${MASTER_SITE_GITHUB:=intel/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/intel/opencl-clang
COMMENT=	OpenCL-oriented wrapper library around clang
LICENSE=	modified-bsd

USE_CMAKE=	yes
USE_LANGUAGES=	c c++

# C++14
GCC_REQD+=	7 # sync with llvm/clang

.include "../../parallel/spirv-llvm-translator/buildlink3.mk"
.include "../../lang/clang/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
