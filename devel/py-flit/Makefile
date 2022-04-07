# $NetBSD: Makefile,v 1.4 2022/04/07 12:28:15 adam Exp $

DISTNAME=	flit-3.7.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=f/flit/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://flit.readthedocs.io/
COMMENT=	Simple packaging tool for simple packages
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-docutils>=0:../../textproc/py-docutils
DEPENDS+=	${PYPKGPREFIX}-flit_core-${PKGVERSION_NOREV}:../../devel/py-flit_core
DEPENDS+=	${PYPKGPREFIX}-requests>=0:../../devel/py-requests
DEPENDS+=	${PYPKGPREFIX}-tomli>=0:../../textproc/py-tomli
DEPENDS+=	${PYPKGPREFIX}-tomli_w>=0:../../textproc/py-tomli_w
TEST_DEPENDS+=	${PYPKGPREFIX}-responses>=0:../../net/py-responses
TEST_DEPENDS+=	${PYPKGPREFIX}-test>=2.7.3:../../devel/py-test
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov>=0:../../devel/py-test-cov
TEST_DEPENDS+=	${PYPKGPREFIX}-testpath>=0:../../devel/py-testpath

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} flit flit-${PYVERSSUFFIX} || ${TRUE}

do-test:
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} pytest-${PYVERSSUFFIX} tests

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
