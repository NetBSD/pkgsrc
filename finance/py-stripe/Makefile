# $NetBSD: Makefile,v 1.83 2026/08/20 09:19:19 adam Exp $

DISTNAME=	stripe-15.5.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	finance python
MASTER_SITES=	${MASTER_SITE_PYPI:=s/stripe/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/stripe/stripe-python
COMMENT=	Stripe python bindings
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-flit_core>=3.11:../../devel/py-flit_core
DEPENDS+=	${PYPKGPREFIX}-requests>=2.20:../../devel/py-requests
DEPENDS+=	${PYPKGPREFIX}-typing-extensions>=4.7.0:../../devel/py-typing-extensions
# tests require stripe-mock
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov>=2.5:../../devel/py-test-cov
TEST_DEPENDS+=	${PYPKGPREFIX}-test-mock>=1.7:../../devel/py-test-mock
TEST_DEPENDS+=	${PYPKGPREFIX}-test-xdist>=1.22:../../devel/py-test-xdist

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
