# $NetBSD: Makefile,v 1.2 2018/01/17 12:07:19 adam Exp $

DISTNAME=	patsy-0.5.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/patsy/}

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://pypi.python.org/pypi/patsy/
COMMENT=	Python package for describing statistical models
LICENSE=	2-clause-bsd

DEPENDS+=	${PYPKGPREFIX}-numpy>=1.4:../../math/py-numpy
DEPENDS+=	${PYPKGPREFIX}-six-[0-9]*:../../lang/py-six
# TEST_DEPENDS
BUILD_DEPENDS+=	${PYPKGPREFIX}-nose-[0-9]*:../../devel/py-nose

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
