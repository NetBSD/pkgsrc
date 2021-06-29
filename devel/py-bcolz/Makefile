# $NetBSD: Makefile,v 1.9 2021/06/29 08:41:59 nia Exp $

DISTNAME=	bcolz-1.2.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=b/bcolz/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/Blosc/bcolz
COMMENT=	Columnar and compressed data containers
LICENSE=	modified-bsd

BUILD_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm>=1.15.0:../../devel/py-setuptools_scm

MAKE_ENV+=	BLOSC_DIR=${BUILDLINK_PREFIX.blosc}

PYTHON_VERSIONS_INCOMPATIBLE=	36 # py-numpy

.include "../../devel/blosc/buildlink3.mk"
.include "../../devel/py-cython/buildlink3.mk"
BUILDLINK_API_DEPENDS.py-numpy+=	${PYPKGPREFIX}-numpy>=1.8
.include "../../math/py-numpy/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
