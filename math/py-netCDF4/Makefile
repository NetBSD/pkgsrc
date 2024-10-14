# $NetBSD: Makefile,v 1.30 2024/10/14 06:45:50 wiz Exp $

DISTNAME=	netcdf4-1.7.1.post1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/cdf/CDF/}
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_PYPI:=n/netCDF4/}

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://github.com/Unidata/netcdf4-python
COMMENT=	Object-oriented python interface to netCDF version 4
LICENSE=	mit

WHEEL_NAME=	netCDF4-${PKGVERSION_NOREV}

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=61:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel
DEPENDS+=	${PYPKGPREFIX}-certifi-[0-9]*:../../security/py-certifi
DEPENDS+=	${PYPKGPREFIX}-cftime-[0-9]*:../../time/py-cftime

USE_TOOLS+=	pkg-config

SUBST_CLASSES+=		paths
SUBST_STAGE.paths=	pre-configure
SUBST_SED.paths+=	-e 's,/usr/local,${PREFIX},g'
SUBST_FILES.paths+=	setup.py
SUBST_MESSAGE.paths=	Fixing header search paths.

post-install:
.for bin in nc3tonc4 nc4tonc3 ncinfo
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} ${bin} ${bin}-${PYVERSSUFFIX} || ${TRUE}
.endfor

do-test:
	cd ${WRKSRC}/test && ${SETENV} ${TEST_ENV} ${PYTHONBIN} run_all.py

.include "../../devel/hdf5/buildlink3.mk"
.include "../../devel/netcdf/buildlink3.mk"
.include "../../devel/py-cython/buildlink3.mk"
.include "../../lang/python/wheel.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
