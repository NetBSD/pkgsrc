# $NetBSD: Makefile,v 1.20 2024/10/14 06:45:39 wiz Exp $

DISTNAME=	h5py-3.11.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=h/h5py/}

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://www.h5py.org/
COMMENT=	Python interface to the HDF5 library
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-cython-[0-9]*:../../devel/py-cython
TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel
#TEST_DEPENDS+=	py-test-mpi

MAKE_ENV=	HDF5_DIR=${PREFIX}

BUILDLINK_API_DEPENDS.hdf5+=	hdf5>=1.10.4
.include "../../devel/hdf5/buildlink3.mk"
.include "../../devel/py-cython/buildlink3.mk"
.include "../../lang/python/wheel.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
