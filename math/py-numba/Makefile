# $NetBSD: Makefile,v 1.42 2026/06/28 15:41:29 wiz Exp $

DISTNAME=	numba-0.65.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_PYPI:=n/numba/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://numba.pydata.org/
COMMENT=	NumPy aware dynamic Python compiler using LLVM
LICENSE=	2-clause-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-llvmlite>=0.47.0:../../devel/py-llvmlite

# TODO: enable OpenMP properly, like other packages.
MAKE_ENV+=	NUMBA_DISABLE_OPENMP=1

USE_LANGUAGES=	c c++

PY_RENAME_BINARIES=	numba

PYTHON_VERSIONS_INCOMPATIBLE=	310 311

.include "../../lang/python/wheel.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../parallel/threadingbuildingblocks/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
