# $NetBSD: Makefile,v 1.17 2023/08/31 11:58:40 adam Exp $

DISTNAME=	h5py-3.9.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=h/h5py/}

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://www.h5py.org/
COMMENT=	Python interface to the HDF5 library
LICENSE=	modified-bsd

MAKE_ENV=	HDF5_DIR=${PREFIX}

PYTHON_VERSIONS_INCOMPATIBLE=	27 38

BUILDLINK_API_DEPENDS.hdf5+=	hdf5>=1.10
.include "../../devel/hdf5/buildlink3.mk"
.include "../../devel/py-cython/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
