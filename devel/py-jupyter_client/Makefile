# $NetBSD: Makefile,v 1.2 2017/05/04 19:47:48 adam Exp $

DISTNAME=	jupyter_client-5.0.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_PYPI:=j/jupyter_client/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://jupyter.org/
COMMENT=	Jupyter protocol implementation and client libraries
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-traitlets>=4.1.0:../../devel/py-traitlets
DEPENDS+=	${PYPKGPREFIX}-jupyter_core-[0-9]*:../../devel/py-jupyter_core
DEPENDS+=	${PYPKGPREFIX}-zmq>=13.0.0:../../net/py-zmq
DEPENDS+=	${PYPKGPREFIX}-dateutil>=2.1:../../time/py-dateutil

USE_LANGUAGES=	# none

post-install:
	${MV} ${DESTDIR}${PREFIX}/bin/jupyter-kernelspec ${DESTDIR}${PREFIX}/bin/jupyter-kernelspec${PYVERSSUFFIX}

.include "../../lang/python/distutils.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
