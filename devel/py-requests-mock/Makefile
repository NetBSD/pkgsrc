# $NetBSD: Makefile,v 1.16 2022/01/27 10:57:32 wiz Exp $

DISTNAME=	requests-mock-1.9.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel www python
MASTER_SITES=	${MASTER_SITE_PYPI:=r/requests-mock/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://requests-mock.readthedocs.org/
COMMENT=	Mock out responses from the requests package
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-requests>=2.3:../../devel/py-requests
DEPENDS+=	${PYPKGPREFIX}-six-[0-9]*:../../lang/py-six
BUILD_DEPENDS+=	${PYPKGPREFIX}-pbr-[0-9]*:../../devel/py-pbr
TEST_DEPENDS+=	${PYPKGPREFIX}-fixtures-[0-9]*:../../devel/py-fixtures
TEST_DEPENDS+=	${PYPKGPREFIX}-mock-[0-9]*:../../devel/py-mock
TEST_DEPENDS+=	${PYPKGPREFIX}-purl-[0-9]*:../../www/py-purl
TEST_DEPENDS+=	${PYPKGPREFIX}-testrepository>=0.0.18:../../devel/py-testrepository

USE_LANGUAGES=	# none

PYTHON_VERSIONED_DEPENDENCIES=	sphinx:test test:test testtools:test

do-test:
	cd ${WRKSRC} && pytest-${PYVERSSUFFIX} tests

.include "../../lang/python/egg.mk"
.include "../../lang/python/versioned_dependencies.mk"
.include "../../mk/bsd.pkg.mk"
