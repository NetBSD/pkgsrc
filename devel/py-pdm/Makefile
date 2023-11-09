# $NetBSD: Makefile,v 1.16 2023/11/09 08:52:43 adam Exp $

DISTNAME=	pdm-2.10.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pdm/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pdm.fming.dev/
COMMENT=	Modern Python package and dependency manager
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-pdm_backend-[0-9]*:../../devel/py-pdm_backend
DEPENDS+=	${PYPKGPREFIX}-blinker-[0-9]*:../../devel/py-blinker
DEPENDS+=	${PYPKGPREFIX}-cachecontrol>=0.13.0:../../devel/py-cachecontrol
DEPENDS+=	${PYPKGPREFIX}-certifi-[0-9]*:../../security/py-certifi
DEPENDS+=	${PYPKGPREFIX}-dotenv>=0.15:../../devel/py-dotenv
DEPENDS+=	${PYPKGPREFIX}-findpython>=0.4.0:../../lang/py-findpython
DEPENDS+=	${PYPKGPREFIX}-installer>=0.7:../../misc/py-installer
DEPENDS+=	${PYPKGPREFIX}-packaging>=22.1:../../devel/py-packaging
DEPENDS+=	${PYPKGPREFIX}-platformdirs-[0-9]*:../../misc/py-platformdirs
DEPENDS+=	${PYPKGPREFIX}-pyproject_hooks-[0-9]*:../../devel/py-pyproject_hooks
DEPENDS+=	${PYPKGPREFIX}-requests-toolbelt-[0-9]*:../../devel/py-requests-toolbelt
DEPENDS+=	${PYPKGPREFIX}-resolvelib>=1.0.1:../../devel/py-resolvelib
DEPENDS+=	${PYPKGPREFIX}-shellingham>=1.3.2:../../misc/py-shellingham
DEPENDS+=	${PYPKGPREFIX}-rich>=12.3.0:../../comms/py-rich
DEPENDS+=	${PYPKGPREFIX}-tomlkit>=0.11.1:../../textproc/py-tomlkit
DEPENDS+=	${PYPKGPREFIX}-unearth>=0.12.1:../../net/py-unearth
DEPENDS+=	${PYPKGPREFIX}-virtualenv>=20:../../devel/py-virtualenv
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov-[0-9]*:../../devel/py-test-cov
TEST_DEPENDS+=	${PYPKGPREFIX}-test-httpserver>=1.0.6:../../devel/py-test-httpserver
TEST_DEPENDS+=	${PYPKGPREFIX}-test-rerunfailures>=10.2:../../devel/py-test-rerunfailures
TEST_DEPENDS+=	${PYPKGPREFIX}-test-xdist>=1.31.0:../../devel/py-test-xdist

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27 38

.include "../../lang/python/pyversion.mk"
.if ${PYTHON_VERSION} < 309
DEPENDS+=	${PYPKGPREFIX}-importlib-resources>=5:../../devel/py-importlib-resources
.endif
.if ${PYTHON_VERSION} < 310
DEPENDS+=	${PYPKGPREFIX}-importlib-metadata>=3.6:../../devel/py-importlib-metadata
.endif
.if ${PYTHON_VERSION} < 311
DEPENDS+=	${PYPKGPREFIX}-tomli>=1.1.0:../../textproc/py-tomli
.endif
.if ${PYTHON_VERSION} >= 310
DEPENDS+=	${PYPKGPREFIX}-truststore-[0-9]*:../../security/py-truststore
.endif

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} pdm pdm-${PYVERSSUFFIX} || ${TRUE}

do-test:
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} pytest-${PYVERSSUFFIX} tests

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
