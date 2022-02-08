# $NetBSD: Makefile,v 1.31 2022/02/08 08:51:12 adam Exp $

DISTNAME=	ipykernel-6.9.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=i/ipykernel/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ipython.org/
COMMENT=	IPython Kernel for Jupyter
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-debugpy>=1.0.0:../../devel/py-debugpy
DEPENDS+=	${PYPKGPREFIX}-ipython>=7.23.1:../../devel/py-ipython
DEPENDS+=	${PYPKGPREFIX}-jupyter_client-[0-9]*:../../devel/py-jupyter_client
DEPENDS+=	${PYPKGPREFIX}-matplotlib-inline>=0.1.0:../../graphics/py-matplotlib-inline
DEPENDS+=	${PYPKGPREFIX}-nest-asyncio-[0-9]*:../../devel/py-nest-asyncio
DEPENDS+=	${PYPKGPREFIX}-tornado>=4.2:../../www/py-tornado
DEPENDS+=	${PYPKGPREFIX}-traitlets>=5.1.0:../../devel/py-traitlets
TEST_DEPENDS+=	${PYPKGPREFIX}-flaky-[0-9]*:../../devel/py-flaky
TEST_DEPENDS+=	${PYPKGPREFIX}-ipyparallel-[0-9]*:../../parallel/py-ipyparallel
TEST_DEPENDS+=	${PYPKGPREFIX}-test>=5.3.5:../../devel/py-test
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov-[0-9]*:../../devel/py-test-cov

.include "../../mk/bsd.prefs.mk"
.if ${OPSYS} == "Darwin"
DEPENDS+=	${PYPKGPREFIX}-appnope-[0-9]*:../../sysutils/py-appnope
.endif

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27 37

do-test:
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} pytest-${PYVERSSUFFIX}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
