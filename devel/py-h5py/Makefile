# $NetBSD: Makefile,v 1.28 2026/09/07 16:18:52 adam Exp $

DISTNAME=	h5py-3.16.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=h/h5py/}

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://www.h5py.org/
COMMENT=	Python interface to the HDF5 library
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-cython>=3.0.0:../../devel/py-cython
TOOL_DEPENDS+=	${PYPKGPREFIX}-packaging>=23.0:../../devel/py-packaging
TOOL_DEPENDS+=	${PYPKGPREFIX}-pkgconfig>=1.5.5:../../devel/py-pkgconfig
TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
#TEST_DEPENDS+=	py-test-mpi

MAKE_ENV=	HDF5_DIR=${PREFIX}

PYTHON_VERSIONS_INCOMPATIBLE=	310 311

BUILDLINK_API_DEPENDS.hdf5+=	hdf5>=1.10.4
.include "../../devel/hdf5/buildlink3.mk"
.include "../../devel/py-cython/buildlink3.mk"
.include "../../lang/python/wheel.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
