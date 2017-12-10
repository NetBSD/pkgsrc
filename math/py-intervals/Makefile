# $NetBSD: Makefile,v 1.5 2017/12/10 17:01:48 adam Exp $

DISTNAME=	intervals-0.8.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_PYPI:=i/intervals/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/kvesteri/intervals
COMMENT=	Tools for handling intervals (ranges of comparable objects)
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-infinity>=0.1.3:../../math/py-infinity
BUILD_DEPENDS+=	${PYPKGPREFIX}-flake8>=2.4.0:../../devel/py-flake8
BUILD_DEPENDS+=	${PYPKGPREFIX}-isort>=4.2.2:../../devel/py-isort
BUILD_DEPENDS+=	${PYPKGPREFIX}-pygments>=1.2:../../textproc/py-pygments
BUILD_DEPENDS+=	${PYPKGPREFIX}-test>=2.2.3:../../devel/py-test

USE_LANGUAGES=	# none

do-test:
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} pytest-${PYVERSSUFFIX}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
