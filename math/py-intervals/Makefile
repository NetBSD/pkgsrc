# $NetBSD: Makefile,v 1.6 2020/05/17 18:57:26 adam Exp $

DISTNAME=	intervals-0.8.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_PYPI:=i/intervals/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/kvesteri/intervals
COMMENT=	Tools for handling intervals (ranges of comparable objects)
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-infinity>=0.1.3:../../math/py-infinity
TEST_DEPENDS+=	${PYPKGPREFIX}-flake8>=2.4.0:../../devel/py-flake8
TEST_DEPENDS+=	${PYPKGPREFIX}-isort>=4.2.2:../../devel/py-isort
TEST_DEPENDS+=	${PYPKGPREFIX}-pygments>=1.2:../../textproc/py-pygments

PYTHON_VERSIONED_DEPENDENCIES=	test:test

USE_LANGUAGES=	# none

do-test:
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} pytest-${PYVERSSUFFIX}

.include "../../lang/python/egg.mk"
.include "../../lang/python/versioned_dependencies.mk"
.include "../../mk/bsd.pkg.mk"
