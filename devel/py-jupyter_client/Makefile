# $NetBSD: Makefile,v 1.10 2019/07/22 08:42:49 nia Exp $

DISTNAME=	jupyter_client-5.2.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=j/jupyter_client/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://jupyter.org/
COMMENT=	Jupyter protocol implementation and client libraries
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-dateutil>=2.1:../../time/py-dateutil
DEPENDS+=	${PYPKGPREFIX}-jupyter_core-[0-9]*:../../devel/py-jupyter_core
DEPENDS+=	${PYPKGPREFIX}-tornado>=4.1:../../www/py-tornado
DEPENDS+=	${PYPKGPREFIX}-traitlets>=4.1.0:../../devel/py-traitlets
DEPENDS+=	${PYPKGPREFIX}-zmq>=13.0.0:../../net/py-zmq
TEST_DEPENDS+=	${PYPKGPREFIX}-ipykernel-[0-9]*:../../devel/py-ipykernel
TEST_DEPENDS+=	${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test

PYTHON_VERSIONED_DEPENDENCIES=	ipython:test

USE_LANGUAGES=	# none

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} jupyter-kernel jupyter-kernel-${PYVERSSUFFIX} && \
	${MV} jupyter-kernelspec jupyter-kernelspec-${PYVERSSUFFIX} && \
	${MV} jupyter-run jupyter-run-${PYVERSSUFFIX} || ${TRUE}

do-test:
	cd ${WRKSRC} && py.test-${PYVERSSUFFIX}

.include "../../lang/python/egg.mk"
.include "../../lang/python/versioned_dependencies.mk"
.include "../../mk/bsd.pkg.mk"
