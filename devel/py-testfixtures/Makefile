# $NetBSD: Makefile,v 1.11 2026/10/26 05:51:52 adam Exp $

DISTNAME=	testfixtures-12.4.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=t/testfixtures/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/simplistix/testfixtures
COMMENT=	Helpers and mocks useful for automated tests in Python
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-hatchling>=0:../../devel/py-hatchling
TEST_DEPENDS+=	${PYPKGPREFIX}-django>=0:../../www/py-django4
TEST_DEPENDS+=	${PYPKGPREFIX}-mypy>=0:../../lang/py-mypy
# circular dependency
#TEST_DEPENDS+=	${PYPKGPREFIX}-sybil>=6:../../devel/py-sybil
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov>=0:../../devel/py-test-cov
TEST_DEPENDS+=	${PYPKGPREFIX}-test-django>=0:../../www/py-test-django
TEST_DEPENDS+=	${PYPKGPREFIX}-twisted>=0:../../net/py-twisted

USE_LANGUAGES=	# none

.include "../../lang/python/pyversion.mk"
.if ${PYTHON_VERSION} < 313
DEPENDS+=	${PYPKGPREFIX}-typing-extensions>=4.12:../../devel/py-typing-extensions
.endif

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
