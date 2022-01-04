# $NetBSD: Makefile,v 1.29 2022/01/04 20:53:11 wiz Exp $

DISTNAME=	ipykernel-5.5.5
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=i/ipykernel/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ipython.org/
COMMENT=	IPython Kernel for Jupyter
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-ipython>=6.0.0:../../devel/py-ipython
DEPENDS+=	${PYPKGPREFIX}-jupyter_client-[0-9]*:../../devel/py-jupyter_client
DEPENDS+=	${PYPKGPREFIX}-tornado>=4.2:../../www/py-tornado
DEPENDS+=	${PYPKGPREFIX}-traitlets>=4.1.0:../../devel/py-traitlets
DEPENDS+=	${PYPKGPREFIX}-ipython_genutils-[0-9]*:../../devel/py-ipython_genutils

TEST_DEPENDS+=	${PYPKGPREFIX}-flaky-[0-9]*:../../devel/py-flaky
TEST_DEPENDS+=	${PYPKGPREFIX}-nose-[0-9]*:../../devel/py-nose
TEST_DEPENDS+=	${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov-[0-9]*:../../devel/py-test-cov

.include "../../mk/bsd.prefs.mk"
.if ${OPSYS} == "Darwin"
DEPENDS+=	${PYPKGPREFIX}-appnope-[0-9]*:../../sysutils/py-appnope
.endif

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

do-test:
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} pytest-${PYVERSSUFFIX}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
