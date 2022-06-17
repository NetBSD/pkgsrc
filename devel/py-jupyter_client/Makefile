# $NetBSD: Makefile,v 1.31 2022/06/17 10:54:56 adam Exp $

DISTNAME=	jupyter_client-7.3.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=j/jupyter_client/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://jupyter-client.readthedocs.io/
COMMENT=	Jupyter protocol implementation and client libraries
LICENSE=	modified-bsd

BUILD_DEPENDS+=	${PYPKGPREFIX}-hatchling>=0.25:../../devel/py-hatchling
DEPENDS+=	${PYPKGPREFIX}-entrypoints-[0-9]*:../../devel/py-entrypoints
DEPENDS+=	${PYPKGPREFIX}-dateutil>=2.8.2:../../time/py-dateutil
DEPENDS+=	${PYPKGPREFIX}-jupyter_core>=4.9.2:../../devel/py-jupyter_core
DEPENDS+=	${PYPKGPREFIX}-nest-asyncio>=1.5.4:../../devel/py-nest-asyncio
DEPENDS+=	${PYPKGPREFIX}-tornado>=6.0:../../www/py-tornado
DEPENDS+=	${PYPKGPREFIX}-traitlets>=4.1.0:../../devel/py-traitlets
DEPENDS+=	${PYPKGPREFIX}-zmq>=23.0:../../net/py-zmq
TEST_DEPENDS+=	${PYPKGPREFIX}-ipykernel>=6.5:../../devel/py-ipykernel
TEST_DEPENDS+=	${PYPKGPREFIX}-ipython-[0-9]*:../../devel/py-ipython
TEST_DEPENDS+=	${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test
TEST_DEPENDS+=	${PYPKGPREFIX}-test-asyncio>=0.18:../../devel/py-test-asyncio
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov-[0-9]*:../../devel/py-test-cov
TEST_DEPENDS+=	${PYPKGPREFIX}-test-timeout-[0-9]*:../../devel/py-test-timeout

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

USE_PKG_RESOURCES=	yes

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} jupyter-kernel jupyter-kernel-${PYVERSSUFFIX} && \
	${MV} jupyter-kernelspec jupyter-kernelspec-${PYVERSSUFFIX} && \
	${MV} jupyter-run jupyter-run-${PYVERSSUFFIX} || ${TRUE}

do-test:
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} pytest-${PYVERSSUFFIX}

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
