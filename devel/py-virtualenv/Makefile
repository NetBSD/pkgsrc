# $NetBSD: Makefile,v 1.78 2023/10/28 19:57:08 wiz Exp $

DISTNAME=	virtualenv-20.24.6
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=v/virtualenv/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://virtualenv.pypa.io/
COMMENT=	Virtual Python Environment builder
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-hatch-vcs>=0.3:../../devel/py-hatch-vcs
TOOL_DEPENDS+=	${PYPKGPREFIX}-hatchling>=1.14:../../devel/py-hatchling
DEPENDS+=	${PYPKGPREFIX}-distlib>=0.3.6:../../devel/py-distlib
DEPENDS+=	${PYPKGPREFIX}-filelock>=3.11:../../devel/py-filelock
DEPENDS+=	${PYPKGPREFIX}-platformdirs>=3.2:../../misc/py-platformdirs
TEST_DEPENDS+=	${PYPKGPREFIX}-coverage>=6.2:../../devel/py-coverage
TEST_DEPENDS+=	${PYPKGPREFIX}-coverage-enable-subprocess>=1:../../devel/py-coverage-enable-subprocess
TEST_DEPENDS+=	${PYPKGPREFIX}-flaky>=3.7:../../devel/py-flaky
TEST_DEPENDS+=	${PYPKGPREFIX}-packaging>=23.1:../../devel/py-packaging
TEST_DEPENDS+=	${PYPKGPREFIX}-test>=7.3.1:../../devel/py-test
TEST_DEPENDS+=	${PYPKGPREFIX}-test-env>=0.8.1:../../devel/py-test-env
TEST_DEPENDS+=	${PYPKGPREFIX}-test-freezegun>=0.4.6:../../devel/py-test-freezegun
TEST_DEPENDS+=	${PYPKGPREFIX}-test-mock>=3.10:../../devel/py-test-mock
TEST_DEPENDS+=	${PYPKGPREFIX}-test-randomly>=3.12:../../devel/py-test-randomly
TEST_DEPENDS+=	${PYPKGPREFIX}-test-timeout>=2.1:../../devel/py-test-timeout
TEST_DEPENDS+=	${PYPKGPREFIX}-time-machine>=2.9:../../time/py-time-machine

PYTHON_VERSIONS_INCOMPATIBLE=	27

USE_LANGUAGES=	c # for tests

REPLACE_PYTHON=	virtualenv.py

post-install:
	# see patches
	${RM} ${DESTDIR}${PREFIX}/${PYSITELIB}/virtualenv/create/via_global_ref/api.py.orig
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} virtualenv virtualenv-${PYVERSSUFFIX} || ${TRUE}

# needs 'make install' and USE_LANGUAGES=c
do-test:
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} pytest-${PYVERSSUFFIX} tests

.include "../../lang/python/batteries-included.mk"
.include "../../lang/python/application.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
