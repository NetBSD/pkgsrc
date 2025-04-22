# $NetBSD: Makefile,v 1.19 2025/04/22 20:11:44 wiz Exp $

DISTNAME=	requests-toolbelt-1.0.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=r/requests-toolbelt/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://toolbelt.readthedocs.io/
COMMENT=	Utility belt for advanced users of python-requests
LICENSE=	apache-2.0

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-requests>=2.0.1:../../devel/py-requests
TEST_DEPENDS+=	${PYPKGPREFIX}-betamax-[0-9]*:../../www/py-betamax
TEST_DEPENDS+=	${PYPKGPREFIX}-mock-[0-9]*:../../devel/py-mock
TEST_DEPENDS+=	${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test
TEST_DEPENDS+=	${PYPKGPREFIX}-trustme-[0-9]*:../../security/py-trustme

USE_LANGUAGES=	# none

# as of 1.0.0
# 6 failed, 156 passed, 7 skipped, 24 warnings

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
