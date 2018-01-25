# $NetBSD: Makefile,v 1.6 2018/01/25 09:51:57 adam Exp $

DISTNAME=	ipykernel-4.8.0
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
BUILD_DEPENDS+=	${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test

USE_LANGUAGES=	# none

PYTHON_VERSIONED_DEPENDENCIES=	ipython

.include "../../lang/python/pyversion.mk"
PLIST_VARS+=    async
.if "${PYPKGPREFIX}" != "py27" &&  "${PYPKGPREFIX}" != "py34"
PLIST.async=    yes
.endif

do-test:
	cd ${WRKSRC} && py.test-${PYVERSSUFFIX}

.include "../../lang/python/distutils.mk"
.include "../../lang/python/versioned_dependencies.mk"
.include "../../mk/bsd.pkg.mk"
