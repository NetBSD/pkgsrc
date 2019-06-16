# $NetBSD: Makefile,v 1.7 2019/06/16 14:11:49 adam Exp $

DISTNAME=	h5py-2.9.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=h/h5py/}

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://www.h5py.org/
COMMENT=	Python interface to the HDF5 library
LICENSE=	modified-bsd

BUILD_DEPENDS+=	${PYPKGPREFIX}-pkgconfig-[0-9]*:../../devel/py-pkgconfig
DEPENDS+=	${PYPKGPREFIX}-six-[0-9]*:../../lang/py-six

BUILDLINK_API_DEPENDS.hdf5+=	hdf5>=1.10
.include "../../devel/hdf5/buildlink3.mk"
.include "../../devel/py-cython/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
