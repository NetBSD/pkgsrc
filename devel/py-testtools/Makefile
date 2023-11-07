# $NetBSD: Makefile,v 1.24 2023/11/07 22:38:01 wiz Exp $

DISTNAME=	testtools-2.6.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=t/testtools/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/testing-cabal/testtools
COMMENT=	Extensions to the Python standard library unit testing framework
LICENSE=	mit AND python-software-foundation

DEPENDS+=	${PYPKGPREFIX}-fixtures>=2.0:../../devel/py-fixtures
DEPENDS+=	${PYPKGPREFIX}-pbr>=0.11:../../devel/py-pbr

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27 38

# circular test dependency
# https://github.com/testing-cabal/testscenarios/issues/4
#TEST_DEPENDS+=	${PYPKGPREFIX}-testscenarios-[0-9]*:../../devel/py-testscenarios

do-test:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} PYTHONPATH=${PWD} ${PYTHONBIN} -m testtools.run testtools.tests.test_suite

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
