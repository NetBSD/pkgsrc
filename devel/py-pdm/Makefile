# $NetBSD: Makefile,v 1.23 2026/11/11 23:34:22 wiz Exp $

DISTNAME=	pdm-2.29.7
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pdm/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pdm.fming.dev/
COMMENT=	Modern Python package and dependency manager
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-pdm_backend-[0-9]*:../../devel/py-pdm_backend
DEPENDS+=	${PYPKGPREFIX}-argcomplete>=3.6.3:../../devel/py-argcomplete
DEPENDS+=	${PYPKGPREFIX}-pbs-installer>=2026.10.25:../../misc/py-pbs-installer
DEPENDS+=	${PYPKGPREFIX}-blinker-[0-9]*:../../devel/py-blinker
DEPENDS+=	${PYPKGPREFIX}-dep-logic>=0.5:../../misc/py-dep-logic
DEPENDS+=	${PYPKGPREFIX}-filelock>=3.13:../../devel/py-filelock
DEPENDS+=	${PYPKGPREFIX}-certifi>=2026.10.19:../../security/py-certifi
DEPENDS+=	${PYPKGPREFIX}-dotenv>=0.15:../../devel/py-dotenv
DEPENDS+=	${PYPKGPREFIX}-findpython>=0.7.0:../../lang/py-findpython
DEPENDS+=	${PYPKGPREFIX}-id>=1.5.0:../../devel/py-id
DEPENDS+=	${PYPKGPREFIX}-httpx2>=2.9:../../www/py-httpx2
DEPENDS+=	${PYPKGPREFIX}-hishel>=2.0:../../www/py-hishel
DEPENDS+=	${PYPKGPREFIX}-installer>=1:../../misc/py-installer
DEPENDS+=	${PYPKGPREFIX}-packaging>=22.0:../../devel/py-packaging
DEPENDS+=	${PYPKGPREFIX}-platformdirs-[0-9]*:../../misc/py-platformdirs
DEPENDS+=	${PYPKGPREFIX}-pyproject_hooks-[0-9]*:../../devel/py-pyproject_hooks
DEPENDS+=	${PYPKGPREFIX}-resolvelib>=1.1:../../devel/py-resolvelib
DEPENDS+=	${PYPKGPREFIX}-shellingham>=1.3.2:../../misc/py-shellingham
DEPENDS+=	${PYPKGPREFIX}-rich>=12.3.0:../../comms/py-rich
DEPENDS+=	${PYPKGPREFIX}-tomlkit>=0.11.1:../../textproc/py-tomlkit
DEPENDS+=	${PYPKGPREFIX}-truststore>=0.10.4:../../security/py-truststore
DEPENDS+=	${PYPKGPREFIX}-unearth>=0.19:../../net/py-unearth
DEPENDS+=	${PYPKGPREFIX}-virtualenv>=20:../../devel/py-virtualenv
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov-[0-9]*:../../devel/py-test-cov
TEST_DEPENDS+=	${PYPKGPREFIX}-test-httpserver>=1.0.6:../../devel/py-test-httpserver
TEST_DEPENDS+=	${PYPKGPREFIX}-test-rerunfailures>=10.2:../../devel/py-test-rerunfailures
TEST_DEPENDS+=	${PYPKGPREFIX}-test-xdist>=1.31.0:../../devel/py-test-xdist
# not documented, but used
TEST_DEPENDS+=	${PYPKGPREFIX}-test-mock-[0-9]*:../../devel/py-test-mock

USE_LANGUAGES=	# none

PY_RENAME_BINARIES=	pdm

.if make(test)
ALLOW_NETWORK_ACCESS=	yes
.endif

pre-test:
# needs 'tasks'??
	${RM} -f ${WRKSRC}/tests/test_doc_generation.py

# as of 2.29.7
# 38 failed, 1741 passed, 22 skipped, 61 warnings

.include "../../lang/python/pyversion.mk"

.if ${PYTHON_VERSION} < 311
DEPENDS+=	${PYPKGPREFIX}-tomli>=1.1.0:../../textproc/py-tomli
.endif

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
