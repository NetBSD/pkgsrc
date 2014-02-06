# $NetBSD: Makefile,v 1.1 2014/02/06 14:22:51 drochner Exp $

DISTNAME=	h5py-2.2.1
PKGNAME=        ${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	https://pypi.python.org/packages/source/h/h5py/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://www.h5py.org
COMMENT=	Python interface to the HDF5 library
LICENSE=	modified-bsd

PYDISTUTILSPKG=	yes

PKG_OPTIONS_VAR=	PKG_OPTIONS.h5py
PKG_SUPPORTED_OPTIONS=	cython

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mcython)
.include "../../devel/py-cython/buildlink3.mk"
.endif

.include "../../devel/hdf5/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
