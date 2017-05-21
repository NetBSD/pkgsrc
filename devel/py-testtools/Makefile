# $NetBSD: Makefile,v 1.17 2017/05/21 06:45:39 adam Exp $

DISTNAME=	testtools-2.3.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_PYPI:=t/testtools/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/testing-cabal/testtools
COMMENT=	Extensions to the Python standard library unit testing framework
LICENSE=	mit AND python-software-foundation

DEPENDS+=	${PYPKGPREFIX}-extras>=1.0.0:../../devel/py-extras
DEPENDS+=	${PYPKGPREFIX}-fixtures>=1.3.0:../../devel/py-fixtures
DEPENDS+=	${PYPKGPREFIX}-python-mimeparse-[0-9]*:../../www/py-python-mimeparse
DEPENDS+=	${PYPKGPREFIX}-unittest2>=0.8.0:../../devel/py-unittest2

# 38 failures as of 2.2.0
# https://github.com/testing-cabal/testtools/issues/253
# TEST_DEPENDS
BUILD_DEPENDS+=	${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test
BUILD_DEPENDS+=	${PYPKGPREFIX}-testscenarios-[0-9]*:../../devel/py-testscenarios

USE_LANGUAGES=	# none

do-test:
	cd ${WRKSRC} && py.test-${PYVERSSUFFIX}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
