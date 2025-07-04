# $NetBSD: Makefile,v 1.5 2025/07/04 09:08:38 wiz Exp $

DISTNAME=	h5netcdf-1.3.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=h/h5netcdf/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://h5netcdf.org/
COMMENT=	netCDF4 via h5py
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm>=7.0:../../devel/py-setuptools_scm
DEPENDS+=	${PYPKGPREFIX}-h5py-[0-9]*:../../devel/py-h5py
DEPENDS+=	${PYPKGPREFIX}-packaging-[0-9]*:../../devel/py-packaging
TEST_DEPENDS+=	${PYPKGPREFIX}-netCDF4-[0-9]*:../../math/py-netCDF4

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	39 310

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
