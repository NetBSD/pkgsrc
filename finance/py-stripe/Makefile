# $NetBSD: Makefile,v 1.54 2022/07/08 14:32:11 wiz Exp $

DISTNAME=	stripe-3.5.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	finance python
MASTER_SITES=	${MASTER_SITE_PYPI:=s/stripe/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/stripe/stripe-python
COMMENT=	Stripe python bindings
LICENSE=	mit

BUILD_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel
DEPENDS+=	${PYPKGPREFIX}-requests>=2.20:../../devel/py-requests
# tests require stripe-mock
TEST_DEPENDS+=	${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov>=2.5:../../devel/py-test-cov
TEST_DEPENDS+=	${PYPKGPREFIX}-test-mock>=1.7:../../devel/py-test-mock
TEST_DEPENDS+=	${PYPKGPREFIX}-test-xdist>=1.22:../../devel/py-test-xdist

PYTHON_VERSIONS_INCOMPATIBLE=	27

USE_LANGUAGES=	# none

do-test:
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} pytest-${PYVERSSUFFIX}

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
