# $NetBSD: Makefile,v 1.3 2021/11/20 23:16:37 wiz Exp $

DISTNAME=	opencl-clang-12.0.0
CATEGORIES=	parallel
MASTER_SITES=	${MASTER_SITE_GITHUB:=intel/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/intel/opencl-clang
COMMENT=	OpenCL-oriented wrapper library around clang
LICENSE=	modified-bsd

USE_CMAKE=	yes
# there is a bug somewhere..
# make[2]: Graph cycles through `cl_headers/module.modulemap'
USE_TOOLS+=	gmake
USE_LANGUAGES=	c c++

# C++14
GCC_REQD+=	5

.include "../../mk/bsd.prefs.mk"

pre-configure:
.if empty(PKGSRC_COMPILER:M*clang*)
# XXX: When using GCC, pkgsrc provides 'clang' wrappers that are actually gcc.
# XXX: This is copied from Firefox, which also needs this hack...
	${LN} -sf ${PREFIX}/bin/clang ${WRKDIR}/.cwrapper/bin/clang
	${LN} -sf ${PREFIX}/bin/clang++ ${WRKDIR}/.cwrapper/bin/clang++
	${LN} -sf ${PREFIX}/bin/clang-cpp ${WRKDIR}/.cwrapper/bin/clang-cpp
.endif

.include "../../parallel/spirv-llvm-translator/buildlink3.mk"
.include "../../lang/clang/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
