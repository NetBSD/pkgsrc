# $NetBSD: Makefile,v 1.63 2023/02/08 10:28:52 adam Exp $

DISTNAME=	virtualenv-20.19.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=v/virtualenv/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://virtualenv.pypa.io/
COMMENT=	Virtual Python Environment builder
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-hatch-vcs>=0.3:../../devel/py-hatch-vcs
TOOL_DEPENDS+=	${PYPKGPREFIX}-hatchling>=1.12.2:../../devel/py-hatchling
DEPENDS+=	${PYPKGPREFIX}-distlib>=0.3.6:../../devel/py-distlib
DEPENDS+=	${PYPKGPREFIX}-filelock>=3.4.1:../../devel/py-filelock
DEPENDS+=	${PYPKGPREFIX}-platformdirs>=2.4:../../misc/py-platformdirs
TEST_DEPENDS+=	${PYPKGPREFIX}-coverage>=6.2:../../devel/py-coverage
TEST_DEPENDS+=	${PYPKGPREFIX}-coverage-enable-subprocess>=1:../../devel/py-coverage-enable-subprocess
TEST_DEPENDS+=	${PYPKGPREFIX}-flaky>=3.7:../../devel/py-flaky
TEST_DEPENDS+=	${PYPKGPREFIX}-packaging>=21.3:../../devel/py-packaging
TEST_DEPENDS+=	${PYPKGPREFIX}-test>=7.0.1:../../devel/py-test
TEST_DEPENDS+=	${PYPKGPREFIX}-test-env>=0.6.2:../../devel/py-test-env
TEST_DEPENDS+=	${PYPKGPREFIX}-test-freezegun>=0.4.2:../../devel/py-test-freezegun
TEST_DEPENDS+=	${PYPKGPREFIX}-test-mock>=3.6.1:../../devel/py-test-mock
TEST_DEPENDS+=	${PYPKGPREFIX}-test-randomly>=3.10.3:../../devel/py-test-randomly
TEST_DEPENDS+=	${PYPKGPREFIX}-test-timeout>=2.1:../../devel/py-test-timeout

PYTHON_VERSIONS_INCOMPATIBLE=	27

USE_LANGUAGES=	c # for tests

REPLACE_PYTHON=	virtualenv.py

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} virtualenv virtualenv-${PYVERSSUFFIX} || ${TRUE}

# needs 'make install' and USE_LANGUAGES=c
do-test:
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} pytest-${PYVERSSUFFIX}

.include "../../lang/python/application.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
