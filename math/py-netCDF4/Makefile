# $NetBSD: Makefile,v 1.17 2021/12/30 13:05:36 adam Exp $

DISTNAME=	netCDF4-1.5.8
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_PYPI:=n/netCDF4/}

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://github.com/Unidata/netcdf4-python
COMMENT=	Object-oriented python interface to netCDF version 4
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-cftime-[0-9]*:../../time/py-cftime

USE_TOOLS+=	pkg-config

SUBST_CLASSES+=		paths
SUBST_STAGE.paths=	pre-configure
SUBST_SED.paths+=	-e 's,/usr/local,${PREFIX},g'
SUBST_FILES.paths+=	setup.py
SUBST_MESSAGE.paths=	Fixing header search paths.

PYTHON_VERSIONS_INCOMPATIBLE+=	27 # py-numpy

do-test:
	cd ${WRKSRC}/test && ${SETENV} ${TEST_ENV} ${PYTHONBIN} run_all.py

.include "../../devel/hdf5/buildlink3.mk"
.include "../../devel/netcdf/buildlink3.mk"
.include "../../devel/py-cython/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
