# $NetBSD: Makefile,v 1.2 2020/12/11 08:10:02 adam Exp $

DISTNAME=	jupyter_console-6.2.0
PKGNAME=	${PYPKGPREFIX}-jupyter-console-6.2.0
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=j/jupyter_console/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://jupyter.org/
COMMENT=	Jupyter terminal console
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-jupyter_client>=6.1.7:../../devel/py-jupyter_client
DEPENDS+=	${PYPKGPREFIX}-ipython>=6.5:../../devel/py-ipython
DEPENDS+=	${PYPKGPREFIX}-ipykernel>=5.1:../../devel/py-ipykernel
DEPENDS+=	${PYPKGPREFIX}-prompt_toolkit>=1.0.15:../../devel/py-prompt_toolkit
DEPENDS+=	${PYPKGPREFIX}-pygments>=2.3.1:../../textproc/py-pygments

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27 36	# py-ipykernel

post-install:
.for name in console
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} jupyter-${name} jupyter-${name}-${PYVERSSUFFIX} || ${TRUE}
.endfor

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
