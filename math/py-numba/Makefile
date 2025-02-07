# $NetBSD: Makefile,v 1.38 2025/02/07 03:25:11 ryoon Exp $

DISTNAME=	numba-0.61.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_PYPI:=n/numba/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://numba.pydata.org/
COMMENT=	NumPy aware dynamic Python compiler using LLVM
LICENSE=	2-clause-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-llvmlite>=0.41.0:../../devel/py-llvmlite

# TODO: enable OpenMP properly, like other packages.
MAKE_ENV+=	NUMBA_DISABLE_OPENMP=1

USE_LANGUAGES=	c c++

PYTHON_VERSIONS_ACCEPTED=	313 312 311 310

post-install:
	cd ${DESTDIR}${PREFIX}/bin && ${MV} numba numba-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/wheel.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../parallel/threadingbuildingblocks/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
