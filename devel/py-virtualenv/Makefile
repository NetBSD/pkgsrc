# $NetBSD: Makefile,v 1.116 2026/10/17 08:57:23 adam Exp $

DISTNAME=	virtualenv-21.14.8
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=v/virtualenv/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://virtualenv.pypa.io/
COMMENT=	Virtual Python Environment builder
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-hatch-vcs>=0.5:../../devel/py-hatch-vcs
TOOL_DEPENDS+=	${PYPKGPREFIX}-hatchling>=1.28:../../devel/py-hatchling
DEPENDS+=	${PYPKGPREFIX}-distlib>=0.4.3:../../devel/py-distlib
DEPENDS+=	${PYPKGPREFIX}-filelock>=3.24.2:../../devel/py-filelock
DEPENDS+=	${PYPKGPREFIX}-packaging>=26.3:../../devel/py-packaging
DEPENDS+=	${PYPKGPREFIX}-platformdirs>=4.4:../../misc/py-platformdirs
DEPENDS+=	${PYPKGPREFIX}-python-discovery>=1.6.1:../../lang/py-python-discovery
TEST_DEPENDS+=	${PYPKGPREFIX}-coverage>=7.2.7:../../devel/py-coverage
TEST_DEPENDS+=	${PYPKGPREFIX}-coverage-enable-subprocess>=1:../../devel/py-coverage-enable-subprocess
TEST_DEPENDS+=	${PYPKGPREFIX}-test-env>=1.1.5:../../devel/py-test-env
TEST_DEPENDS+=	${PYPKGPREFIX}-test-freezer>=0.4.8:../../devel/py-test-freezer
TEST_DEPENDS+=	${PYPKGPREFIX}-test-mock>=3.15.1:../../devel/py-test-mock
TEST_DEPENDS+=	${PYPKGPREFIX}-test-randomly>=4.0.1:../../devel/py-test-randomly
TEST_DEPENDS+=	${PYPKGPREFIX}-test-rerunfailures>=16.0.1:../../devel/py-test-rerunfailures
TEST_DEPENDS+=	${PYPKGPREFIX}-test-timeout>=2.4:../../devel/py-test-timeout
TEST_DEPENDS+=	${PYPKGPREFIX}-test-xdist>=3.8:../../devel/py-test-xdist
TEST_DEPENDS+=	${PYPKGPREFIX}-time-machine>=2.19:../../time/py-time-machine

USE_LANGUAGES=	c # for tests

REPLACE_PYTHON=	virtualenv.py

PY_RENAME_BINARIES=	virtualenv

.include "../../lang/python/application.mk"
.include "../../lang/python/batteries-included.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
