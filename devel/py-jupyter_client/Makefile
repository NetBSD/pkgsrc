# $NetBSD: Makefile,v 1.47 2025/12/26 12:52:29 adam Exp $

DISTNAME=	jupyter_client-8.7.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=j/jupyter_client/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://jupyter-client.readthedocs.io/
COMMENT=	Jupyter protocol implementation and client libraries
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-hatchling>=1.5:../../devel/py-hatchling
DEPENDS+=	${PYPKGPREFIX}-dateutil>=2.8.2:../../time/py-dateutil
DEPENDS+=	${PYPKGPREFIX}-jupyter_core>=5.1:../../devel/py-jupyter_core
DEPENDS+=	${PYPKGPREFIX}-tornado>=6.4.1:../../www/py-tornado
DEPENDS+=	${PYPKGPREFIX}-traitlets>=5.3:../../devel/py-traitlets
DEPENDS+=	${PYPKGPREFIX}-zmq>=25.0:../../net/py-zmq
TEST_DEPENDS+=	${PYPKGPREFIX}-ipykernel>=6.14:../../devel/py-ipykernel
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov-[0-9]*:../../devel/py-test-cov
TEST_DEPENDS+=	${PYPKGPREFIX}-test-jupyter>=0.4.1:../../www/py-test-jupyter
TEST_DEPENDS+=	${PYPKGPREFIX}-test-timeout-[0-9]*:../../devel/py-test-timeout

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	310

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} jupyter-kernel jupyter-kernel-${PYVERSSUFFIX} && \
	${MV} jupyter-kernelspec jupyter-kernelspec-${PYVERSSUFFIX} && \
	${MV} jupyter-run jupyter-run-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
