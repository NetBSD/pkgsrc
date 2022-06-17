# $NetBSD: Makefile,v 1.38 2022/06/17 12:22:10 adam Exp $

DISTNAME=	ipykernel-6.15.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=i/ipykernel/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ipython.org/
COMMENT=	IPython Kernel for Jupyter
LICENSE=	modified-bsd

BUILD_DEPENDS+=	${PYPKGPREFIX}-hatchling>=0.25:../../devel/py-hatchling
DEPENDS+=	${PYPKGPREFIX}-debugpy>=1.0.0:../../devel/py-debugpy
DEPENDS+=	${PYPKGPREFIX}-ipython>=7.23.1:../../devel/py-ipython
DEPENDS+=	${PYPKGPREFIX}-jupyter_client>=6.1.12:../../devel/py-jupyter_client
DEPENDS+=	${PYPKGPREFIX}-matplotlib-inline>=0.1.0:../../graphics/py-matplotlib-inline
DEPENDS+=	${PYPKGPREFIX}-nest-asyncio-[0-9]*:../../devel/py-nest-asyncio
DEPENDS+=	${PYPKGPREFIX}-packaging-[0-9]*:../../devel/py-packaging
DEPENDS+=	${PYPKGPREFIX}-psutil-[0-9]*:../../sysutils/py-psutil
DEPENDS+=	${PYPKGPREFIX}-tornado>=6.1:../../www/py-tornado
DEPENDS+=	${PYPKGPREFIX}-traitlets>=5.1.0:../../devel/py-traitlets
DEPENDS+=	${PYPKGPREFIX}-zmq>=17:../../net/py-zmq
TEST_DEPENDS+=	${PYPKGPREFIX}-flaky-[0-9]*:../../devel/py-flaky
TEST_DEPENDS+=	${PYPKGPREFIX}-ipyparallel-[0-9]*:../../parallel/py-ipyparallel
TEST_DEPENDS+=	${PYPKGPREFIX}-test>=6.0.0:../../devel/py-test
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov-[0-9]*:../../devel/py-test-cov
TEST_DEPENDS+=	${PYPKGPREFIX}-test-timeout-[0-9]*:../../devel/py-test-timeout

.include "../../mk/bsd.prefs.mk"
.if ${OPSYS} == "Darwin"
DEPENDS+=	${PYPKGPREFIX}-appnope-[0-9]*:../../sysutils/py-appnope
.endif

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27 37

do-test:
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} pytest-${PYVERSSUFFIX}

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
