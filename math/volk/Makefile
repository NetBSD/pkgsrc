# $NetBSD: Makefile,v 1.13 2022/10/04 09:54:03 adam Exp $

DISTNAME=	volk-2.5.2
CATEGORIES=	math ham
MASTER_SITES=	${MASTER_SITE_GITHUB:=gnuradio/}
GITHUB_RELEASE=	v${PKGVERSION_NOREV}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.libvolk.org/
COMMENT=	The Vector Optimized Library of Kernels
LICENSE=	gnu-gpl-v3

BUILD_DEPENDS+=	${PYPKGPREFIX}-mako-[0-9]*:../../devel/py-mako

GCC_REQD+=	8	# std::filesystem
USE_CMAKE=	yes
USE_LANGUAGES=	c c++17
USE_TOOLS+=	pkg-config
TEST_TARGET=	test

# XXX this doesn't work because VolkPython.cmake doesn't conform
# to PEP 3147 (doesn't place files in __pycache__ when using python 3)
#
# PY_PATCHPLIST=	yes
#.include "../../lang/python/extension.mk"
#
# So do it manually instead:
.include "../../lang/python/pyversion.mk"
PLIST_SUBST+=	PYSITELIB=${PYSITELIB}

.include "../../devel/orc/buildlink3.mk"
.if	${MACHINE_ARCH:M*arm*} ||		\
	${MACHINE_ARCH} == "aarch64" ||		\
	${MACHINE_ARCH} == "i386" ||		\
	${MACHINE_ARCH} == "x86_64" ||		\
	${MACHINE_ARCH:M*mips*} ||		\
	${MACHINE_ARCH:M*powerpc*}
.include "../../devel/cpu_features/buildlink3.mk"
.endif
.include "../../mk/bsd.pkg.mk"
