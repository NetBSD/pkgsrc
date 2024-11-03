# $NetBSD: Makefile,v 1.9 2024/11/03 07:50:30 adam Exp $

DISTNAME=	flit-3.10.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=f/flit/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://flit.readthedocs.io/
COMMENT=	Simple packaging tool for simple packages
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-docutils-[0-9]*:../../textproc/py-docutils
DEPENDS+=	${PYPKGPREFIX}-flit_core-${PKGVERSION_NOREV}{,nb*}:../../devel/py-flit_core
DEPENDS+=	${PYPKGPREFIX}-pip-[0-9]*:../../devel/py-pip
DEPENDS+=	${PYPKGPREFIX}-requests-[0-9]*:../../devel/py-requests
DEPENDS+=	${PYPKGPREFIX}-tomli_w-[0-9]*:../../textproc/py-tomli_w
TEST_DEPENDS+=	${PYPKGPREFIX}-responses-[0-9]*:../../net/py-responses
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov-[0-9]*:../../devel/py-test-cov
TEST_DEPENDS+=	${PYPKGPREFIX}-testpath-[0-9]*:../../devel/py-testpath
TEST_DEPENDS+=	${PYPKGPREFIX}-tomli-[0-9]*:../../textproc/py-tomli

USE_LANGUAGES=	# none

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} flit flit-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
