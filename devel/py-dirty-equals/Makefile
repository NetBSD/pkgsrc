# $NetBSD: Makefile,v 1.6 2025/11/17 17:48:57 adam Exp $

DISTNAME=	dirty_equals-0.11
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=d/dirty-equals/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/samuelcolvin/dirty-equals
COMMENT=	Core functionality for pydantic
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-hatchling-[0-9]*:../../devel/py-hatchling
TEST_DEPENDS+=	${PYPKGPREFIX}-pydantic>=2.4.2:../../devel/py-pydantic
TEST_DEPENDS+=	${PYPKGPREFIX}-test-examples-[0-9]*:../../devel/py-test-examples
TEST_DEPENDS+=	${PYPKGPREFIX}-test-mock-[0-9]*:../../devel/py-test-mock

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
