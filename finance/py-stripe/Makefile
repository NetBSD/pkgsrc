# $NetBSD: Makefile,v 1.22 2020/04/11 07:41:48 adam Exp $

DISTNAME=	stripe-2.45.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	finance python
MASTER_SITES=	${MASTER_SITE_PYPI:=s/stripe/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://stripe.com/
COMMENT=	Stripe python bindings
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-requests>=2.20:../../devel/py-requests
# tests require stripe-mock
TEST_DEPENDS+=	${PYPKGPREFIX}-test>=3.4:../../devel/py-test
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov>=2.5:../../devel/py-test-cov
TEST_DEPENDS+=	${PYPKGPREFIX}-test-mock>=1.7:../../devel/py-test-mock
TEST_DEPENDS+=	${PYPKGPREFIX}-test-xdist>=1.22:../../devel/py-test-xdist

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
