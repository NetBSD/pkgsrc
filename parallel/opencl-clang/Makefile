# $NetBSD: Makefile,v 1.8 2022/08/17 15:34:36 tnn Exp $

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

.for os in Darwin SunOS
BUILDLINK_TRANSFORM.${os}+=	rm:-Wl,--version-script=${WRKDIR}/${DISTNAME}/common_clang.map
.endfor

.include "../../parallel/spirv-llvm-translator/buildlink3.mk"
.include "../../lang/clang/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
