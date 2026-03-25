# $NetBSD: Makefile,v 1.34 2026/03/25 22:59:24 wiz Exp $

DISTNAME=	llvmlite-0.46.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=l/llvmlite/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://llvmlite.readthedocs.io/
COMMENT=	Lightweight LLVM Python binding for writing JIT compilers
LICENSE=	2-clause-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
TOOL_DEPENDS+=	cmake-[0-9]*:../../devel/cmake

# As of 0.45.0, this supports llvm 20.

USE_LANGUAGES=		c c++
USE_CXX_FEATURES=	c++17
USE_TOOLS+=		gmake

.include "../../mk/bsd.prefs.mk"
post-install:
.if ${OPSYS} == "Darwin"
	install_name_tool -id \
		${PREFIX}/${PYSITELIB}/llvmlite/binding/libllvmlite.dylib \
		${DESTDIR}${PREFIX}/${PYSITELIB}/llvmlite/binding/libllvmlite.dylib
.endif

.include "../../lang/python/wheel.mk"
.include "../../lang/llvm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
