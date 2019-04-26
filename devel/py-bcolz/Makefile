# $NetBSD: Makefile,v 1.7 2019/04/26 13:13:51 maya Exp $

DISTNAME=	bcolz-1.2.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=b/bcolz/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/Blosc/bcolz
COMMENT=	Columnar and compressed data containers
LICENSE=	modified-bsd

BUILD_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm>=1.15.0:../../devel/py-setuptools_scm

MAKE_ENV+=	BLOSC_DIR=${BUILDLINK_PREFIX.blosc}

.include "../../devel/blosc/buildlink3.mk"
.include "../../devel/py-cython/buildlink3.mk"
BUILDLINK_API_DEPENDS.py-numpy+=	${PYPKGPREFIX}-numpy>=1.8
.include "../../math/py-numpy/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
