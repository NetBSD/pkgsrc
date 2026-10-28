# $NetBSD: Makefile,v 1.44 2026/10/28 08:16:26 adam Exp $

DISTNAME=	numba-0.68.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_PYPI:=n/numba/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://numba.pydata.org/
COMMENT=	NumPy aware dynamic Python compiler using LLVM
LICENSE=	2-clause-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-llvmlite>=0.50.0:../../devel/py-llvmlite

# TODO: enable OpenMP properly, like other packages.
MAKE_ENV+=	NUMBA_DISABLE_OPENMP=1

USE_LANGUAGES=	c c++

PY_RENAME_BINARIES=	numba

PYTHON_VERSIONS_INCOMPATIBLE=	311

.include "../../lang/python/wheel.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../parallel/threadingbuildingblocks/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
