# $NetBSD: Makefile,v 1.9 2018/11/29 18:24:36 adam Exp $

DISTNAME=	ipykernel-5.1.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=i/ipykernel/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://ipython.org/
COMMENT=	IPython Kernel for Jupyter
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-ipython>=5.0.0:../../devel/py-ipython
DEPENDS+=	${PYPKGPREFIX}-jupyter_client-[0-9]*:../../devel/py-jupyter_client
DEPENDS+=	${PYPKGPREFIX}-tornado>=4.2:../../www/py-tornado
DEPENDS+=	${PYPKGPREFIX}-traitlets>=4.1.0:../../devel/py-traitlets
TEST_DEPENDS+=	${PYPKGPREFIX}-nose-[0-9]*:../../devel/py-nose
TEST_DEPENDS+=	${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov-[0-9]*:../../devel/py-test-cov

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/pyversion.mk"
PLIST_VARS+=    async
.if ${_PYTHON_VERSION} != 34
PLIST.async=    yes
.endif

do-test:
	cd ${WRKSRC} && py.test-${PYVERSSUFFIX}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
