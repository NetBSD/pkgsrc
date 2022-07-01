# $NetBSD: Makefile,v 1.10 2022/07/01 18:06:01 adam Exp $

DISTNAME=	jupyter_console-6.4.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=j/jupyter_console/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://jupyter.org/
COMMENT=	Jupyter terminal console
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-ipython>=6.5:../../devel/py-ipython
DEPENDS+=	${PYPKGPREFIX}-ipykernel>=5.1:../../devel/py-ipykernel
DEPENDS+=	${PYPKGPREFIX}-jupyter_client>=7.0.0:../../devel/py-jupyter_client
DEPENDS+=	${PYPKGPREFIX}-prompt_toolkit>=3.0.2:../../devel/py-prompt_toolkit
DEPENDS+=	${PYPKGPREFIX}-pygments>=2.3.1:../../textproc/py-pygments

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27 37

USE_PKG_RESOURCES=	yes

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} jupyter-console jupyter-console-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
