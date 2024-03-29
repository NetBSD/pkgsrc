# $NetBSD: Makefile,v 1.26 2023/11/08 13:20:02 wiz Exp $

DISTNAME=	netCDF4-1.5.8
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	6
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

PYTHON_VERSIONS_INCOMPATIBLE+=	27 38

USE_PKG_RESOURCES=	yes

do-test:
	cd ${WRKSRC}/test && ${SETENV} ${TEST_ENV} ${PYTHONBIN} run_all.py

.include "../../devel/hdf5/buildlink3.mk"
.include "../../devel/netcdf/buildlink3.mk"
.include "../../devel/py-cython/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
