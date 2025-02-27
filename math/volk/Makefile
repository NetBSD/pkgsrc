# $NetBSD: Makefile,v 1.18 2025/02/27 13:44:29 adam Exp $

DISTNAME=	volk-3.2.0
CATEGORIES=	math ham
MASTER_SITES=	${MASTER_SITE_GITHUB:=gnuradio/}
GITHUB_RELEASE=	v${PKGVERSION_NOREV}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.libvolk.org/
COMMENT=	The Vector Optimized Library of Kernels
LICENSE=	gnu-gpl-v3

TOOL_DEPENDS+=	${PYPKGPREFIX}-mako-[0-9]*:../../devel/py-mako

USE_CXX_FEATURES=	c++17 filesystem
USE_LANGUAGES=		c c++
USE_TOOLS+=		pkg-config
TEST_TARGET=		test

MAKE_ENV+=	LD_LIBRARY_PATH=${WRKSRC}/${CMAKE_BUILD_DIR}/lib
# For Darwin
MAKE_ENV+=	DYLD_LIBRARY_PATH=${WRKSRC}/${CMAKE_BUILD_DIR}/lib

# XXX this doesn't work because VolkPython.cmake doesn't conform
# to PEP 3147 (doesn't place files in __pycache__ when using python 3)
#
# PY_PATCHPLIST=	yes
#.include "../../lang/python/extension.mk"
#
# So do it manually instead:
.include "../../lang/python/pyversion.mk"
PLIST_SUBST+=	PYSITELIB=${PYSITELIB}

.if	${MACHINE_ARCH:M*arm*} ||		\
	${MACHINE_ARCH} == "aarch64" ||		\
	${MACHINE_ARCH} == "i386" ||		\
	${MACHINE_ARCH} == "x86_64" ||		\
	${MACHINE_ARCH:M*mips*} ||		\
	${MACHINE_ARCH:M*powerpc*}
.include "../../devel/cpu_features/buildlink3.mk"
.endif
.include "../../devel/cmake/build.mk"
.include "../../devel/orc/buildlink3.mk"
.include "../../devel/googletest/buildlink3.mk"
.include "../../textproc/fmtlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
