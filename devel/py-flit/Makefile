# $NetBSD: Makefile,v 1.13 2026/09/27 09:33:10 wiz Exp $

DISTNAME=	flit-4.1.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=f/flit/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://flit.readthedocs.io/
COMMENT=	Simple packaging tool for simple packages
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-docutils-[0-9]*:../../textproc/py-docutils
DEPENDS+=	${PYPKGPREFIX}-flit_core>=4.1.0:../../devel/py-flit_core
DEPENDS+=	${PYPKGPREFIX}-pip-[0-9]*:../../devel/py-pip
DEPENDS+=	${PYPKGPREFIX}-requests-[0-9]*:../../devel/py-requests
DEPENDS+=	${PYPKGPREFIX}-tomli_w-[0-9]*:../../textproc/py-tomli_w
TEST_DEPENDS+=	${PYPKGPREFIX}-responses-[0-9]*:../../net/py-responses
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov-[0-9]*:../../devel/py-test-cov
TEST_DEPENDS+=	${PYPKGPREFIX}-testpath-[0-9]*:../../devel/py-testpath
TEST_DEPENDS+=	${PYPKGPREFIX}-tomli-[0-9]*:../../textproc/py-tomli

USE_LANGUAGES=	# none

PY_RENAME_BINARIES=	flit

# as of 4.1.0
# 1 failed, 349 passed, 3 skipped

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
