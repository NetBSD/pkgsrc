# $NetBSD: Makefile,v 1.12 2026/01/08 10:08:12 adam Exp $

# Using passlib's fork, because the original module is stalled.
DISTNAME=	libpass-1.9.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/libpass/passlib/}
CATEGORIES=	security python
MASTER_SITES=	${MASTER_SITE_PYPI:=l/libpass/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/notypecheck/passlib
COMMENT=	Comprehensive password hashing framework supporting over 30 schemes
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-hatchling>0:../../devel/py-hatchling
TEST_DEPENDS+=	${PYPKGPREFIX}-bcrypt>=3.1.0:../../security/py-bcrypt
TEST_DEPENDS+=	${PYPKGPREFIX}-coverage>=7.6.12:../../devel/py-coverage
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov>=6.1.1:../../devel/py-test-cov
TEST_DEPENDS+=	${PYPKGPREFIX}-test-xdist>=3.6.1:../../devel/py-test-xdist

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
