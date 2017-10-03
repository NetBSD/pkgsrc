# $NetBSD: Makefile,v 1.1 2017/10/03 00:43:51 minskim Exp $

DISTNAME=	bcolz-1.1.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_PYPI:=b/bcolz/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/Blosc/bcolz
COMMENT=	Columnar and compressed data containers
LICENSE=	modified-bsd

USE_LANGUAGES=	c

MAKE_ENV+=	BLOSC_DIR=${BUILDLINK_PREFIX.blosc}

.include "../../devel/blosc/buildlink3.mk"
.include "../../devel/py-cython/buildlink3.mk"
.include "../../lang/python/egg.mk"
BUILDLINK_API_DEPENDS.py-numpy+=	${PYPKGPREFIX}-numpy>=1.8
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
