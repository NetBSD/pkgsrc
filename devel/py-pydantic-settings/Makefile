# $NetBSD: Makefile,v 1.3 2024/09/10 18:53:27 adam Exp $

DISTNAME=	pydantic_settings-2.5.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/g}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pydantic_settings/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/pydantic/pydantic-settings
COMMENT=	Settings management using Pydantic
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-hatchling>=0:../../devel/py-hatchling
DEPENDS+=	${PYPKGPREFIX}-pydantic>=2.7.0:../../devel/py-pydantic
DEPENDS+=	${PYPKGPREFIX}-dotenv>=0.21.0:../../devel/py-dotenv
TEST_DEPENDS+=	${PYPKGPREFIX}-test-examples>=0:../../devel/py-test-examples
TEST_DEPENDS+=	${PYPKGPREFIX}-test-mock>=0:../../devel/py-test-mock

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
