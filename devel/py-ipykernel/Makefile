# $NetBSD: Makefile,v 1.5 2017/12/13 08:59:59 adam Exp $

DISTNAME=	ipykernel-4.7.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=i/ipykernel/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://ipython.org/
COMMENT=	IPython Kernel for Jupyter
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-tornado>=4:../../www/py-tornado
DEPENDS+=	${PYPKGPREFIX}-traitlets>=4.1.0:../../devel/py-traitlets
DEPENDS+=	${PYPKGPREFIX}-jupyter_client-[0-9]*:../../devel/py-jupyter_client

USE_LANGUAGES=	# none

PYTHON_VERSIONED_DEPENDENCIES=	ipython

.include "../../lang/python/pyversion.mk"
PLIST_VARS+=    async
.if "${PYPKGPREFIX}" != "py27" &&  "${PYPKGPREFIX}" != "py34"
PLIST.async=    yes
.endif

.include "../../lang/python/distutils.mk"
.include "../../lang/python/versioned_dependencies.mk"
.include "../../mk/bsd.pkg.mk"
