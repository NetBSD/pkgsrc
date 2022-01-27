# $NetBSD: Makefile,v 1.22 2022/01/27 11:24:18 wiz Exp $

DISTNAME=	testtools-2.5.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=t/testtools/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/testing-cabal/testtools
COMMENT=	Extensions to the Python standard library unit testing framework
LICENSE=	mit AND python-software-foundation

DEPENDS+=	${PYPKGPREFIX}-extras>=1.0.0:../../devel/py-extras
DEPENDS+=	${PYPKGPREFIX}-fixtures>=1.3.0:../../devel/py-fixtures
DEPENDS+=	${PYPKGPREFIX}-pbr-[0-9]*:../../devel/py-pbr

PYTHON_VERSIONS_INCOMPATIBLE=	27

# circular test dependency
# https://github.com/testing-cabal/testscenarios/issues/4
#TEST_DEPENDS+=	${PYPKGPREFIX}-testscenarios-[0-9]*:../../devel/py-testscenarios

USE_LANGUAGES=	# none

do-test:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} PYTHONPATH=${PWD} ${PYTHONBIN} -m testtools.run testtools.tests.test_suite

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
