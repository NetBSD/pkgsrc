# $NetBSD: Makefile,v 1.36 2026/04/16 06:36:45 wiz Exp $

DISTNAME=	llvmlite-0.47.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=l/llvmlite/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://llvmlite.readthedocs.io/
COMMENT=	Lightweight LLVM Python binding for writing JIT compilers
LICENSE=	2-clause-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
TOOL_DEPENDS+=	cmake-[0-9]*:../../devel/cmake

USE_CXX_FEATURES=	c++17
USE_LANGUAGES=		c c++
USE_TOOLS+=		gmake

.include "../../mk/bsd.prefs.mk"
post-install:
.if ${OPSYS} == "Darwin"
	install_name_tool -id \
		${PREFIX}/${PYSITELIB}/llvmlite/binding/libllvmlite.dylib \
		${DESTDIR}${PREFIX}/${PYSITELIB}/llvmlite/binding/libllvmlite.dylib
.endif

# As of 0.47.0, the newest version supported is llvm 20.
# So we have to use an in-place llvm build.
.include "inplace.mk"
#.include "../../lang/llvm/buildlink3.mk"

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
