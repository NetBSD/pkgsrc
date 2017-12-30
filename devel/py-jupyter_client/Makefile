# $NetBSD: Makefile,v 1.5 2017/12/30 11:30:13 adam Exp $

DISTNAME=	jupyter_client-5.2.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=j/jupyter_client/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://jupyter.org/
COMMENT=	Jupyter protocol implementation and client libraries
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-dateutil>=2.1:../../time/py-dateutil
DEPENDS+=	${PYPKGPREFIX}-jupyter_core-[0-9]*:../../devel/py-jupyter_core
DEPENDS+=	${PYPKGPREFIX}-traitlets>=4.1.0:../../devel/py-traitlets
DEPENDS+=	${PYPKGPREFIX}-zmq>=13.0.0:../../net/py-zmq
BUILD_DEPENDS+=	${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test

USE_LANGUAGES=	# none

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} jupyter-kernel jupyter-kernel${PYVERSSUFFIX} && \
	${MV} jupyter-kernelspec jupyter-kernelspec${PYVERSSUFFIX} && \
	${MV} jupyter-run jupyter-run${PYVERSSUFFIX} || ${TRUE}

do-test:
	cd ${WRKSRC} && py.test-${PYVERSSUFFIX}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
