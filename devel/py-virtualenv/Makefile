# $NetBSD: Makefile,v 1.87 2024/05/14 09:26:20 adam Exp $

DISTNAME=	virtualenv-20.26.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=v/virtualenv/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://virtualenv.pypa.io/
COMMENT=	Virtual Python Environment builder
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-hatch-vcs>=0.3:../../devel/py-hatch-vcs
TOOL_DEPENDS+=	${PYPKGPREFIX}-hatchling>=1.17.1:../../devel/py-hatchling
DEPENDS+=	${PYPKGPREFIX}-distlib>=0.3.7:../../devel/py-distlib
DEPENDS+=	${PYPKGPREFIX}-filelock>=3.12.2:../../devel/py-filelock
DEPENDS+=	${PYPKGPREFIX}-platformdirs>=3.9.1:../../misc/py-platformdirs
TEST_DEPENDS+=	${PYPKGPREFIX}-coverage>=7.2.7:../../devel/py-coverage
TEST_DEPENDS+=	${PYPKGPREFIX}-coverage-enable-subprocess>=1:../../devel/py-coverage-enable-subprocess
TEST_DEPENDS+=	${PYPKGPREFIX}-flaky>=3.7:../../devel/py-flaky
TEST_DEPENDS+=	${PYPKGPREFIX}-packaging>=23.1:../../devel/py-packaging
TEST_DEPENDS+=	${PYPKGPREFIX}-test-env>=0.8.2:../../devel/py-test-env
TEST_DEPENDS+=	${PYPKGPREFIX}-test-freezer>=0.4.8:../../devel/py-test-freezer
TEST_DEPENDS+=	${PYPKGPREFIX}-test-mock>=3.11.1:../../devel/py-test-mock
TEST_DEPENDS+=	${PYPKGPREFIX}-test-randomly>=3.12:../../devel/py-test-randomly
TEST_DEPENDS+=	${PYPKGPREFIX}-test-timeout>=2.1:../../devel/py-test-timeout
TEST_DEPENDS+=	${PYPKGPREFIX}-time-machine>=2.10:../../time/py-time-machine

USE_LANGUAGES=	c # for tests

REPLACE_PYTHON=	virtualenv.py

PYTHON_VERSIONS_INCOMPATIBLE=	27

post-install:
	# see patches
	${RM} ${DESTDIR}${PREFIX}/${PYSITELIB}/virtualenv/create/via_global_ref/api.py.orig
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} virtualenv virtualenv-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/batteries-included.mk"
.include "../../lang/python/application.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
