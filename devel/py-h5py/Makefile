# $NetBSD: Makefile,v 1.13 2022/04/15 11:37:46 nia Exp $

DISTNAME=	h5py-3.2.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=h/h5py/}

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://www.h5py.org/
COMMENT=	Python interface to the HDF5 library
LICENSE=	modified-bsd

BUILD_DEPENDS+=	${PYPKGPREFIX}-pkgconfig-[0-9]*:../../devel/py-pkgconfig
DEPENDS+=	${PYPKGPREFIX}-six-[0-9]*:../../lang/py-six

MAKE_ENV=	HDF5_DIR=${PREFIX}

PYTHON_VERSIONS_INCOMPATIBLE=	27 37 # numpy

BUILDLINK_API_DEPENDS.hdf5+=	hdf5>=1.10
.include "../../devel/hdf5/buildlink3.mk"
.include "../../devel/py-cython/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
