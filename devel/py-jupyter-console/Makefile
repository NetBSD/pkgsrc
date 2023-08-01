# $NetBSD: Makefile,v 1.13 2023/08/01 23:20:41 wiz Exp $

DISTNAME=	jupyter_console-6.6.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=j/jupyter_console/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://jupyter.org/
COMMENT=	Jupyter terminal console
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-hatchling>=1.5:../../devel/py-hatchling
DEPENDS+=	${PYPKGPREFIX}-ipython>=6.5:../../devel/py-ipython
DEPENDS+=	${PYPKGPREFIX}-ipykernel>=6.14:../../devel/py-ipykernel
DEPENDS+=	${PYPKGPREFIX}-jupyter_client>=7.0.0:../../devel/py-jupyter_client
DEPENDS+=	${PYPKGPREFIX}-jupyter_core>=4.12:../../devel/py-jupyter_core
DEPENDS+=	${PYPKGPREFIX}-prompt_toolkit>=3.0.30:../../devel/py-prompt_toolkit
DEPENDS+=	${PYPKGPREFIX}-pygments>=2.3.1:../../textproc/py-pygments
DEPENDS+=	${PYPKGPREFIX}-zmq>=17:../../net/py-zmq
DEPENDS+=	${PYPKGPREFIX}-traitlets>=5.4:../../devel/py-traitlets

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27 38

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} jupyter-console jupyter-console-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
