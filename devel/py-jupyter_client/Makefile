# $NetBSD: Makefile,v 1.1 2017/04/23 04:27:47 markd Exp $

DISTNAME=	jupyter_client-5.0.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_PYPI:=j/jupyter_client/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://jupyter.org
COMMENT=	Jupyter protocol implementation and client libraries
LICENSE=	modified-bsd

DEPENDS+=       ${PYPKGPREFIX}-traitlets>=4.1.0:../../devel/py-traitlets
DEPENDS+=       ${PYPKGPREFIX}-jupyter_core-[0-9]*:../../devel/py-jupyter_core
DEPENDS+=	${PYPKGPREFIX}-zmq>=13.0.0:../../net/py-zmq
DEPENDS+=	${PYPKGPREFIX}-dateutil>=2.1:../../time/py-dateutil

USE_LANGUAGES=	# none

post-install:
	${MV} ${DESTDIR}${PREFIX}/bin/jupyter-kernelspec ${DESTDIR}${PREFIX}/bin/jupyter-kernelspec${PYVERSSUFFIX}

.include "../../lang/python/distutils.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
