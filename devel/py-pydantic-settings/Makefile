# $NetBSD: Makefile,v 1.7 2024/12/27 08:59:40 wiz Exp $

DISTNAME=	pydantic_settings-2.7.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/g}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pydantic_settings/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/pydantic/pydantic-settings
COMMENT=	Settings management using Pydantic
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-hatchling>=0:../../devel/py-hatchling
DEPENDS+=	${PYPKGPREFIX}-dotenv>=0.21.0:../../devel/py-dotenv
DEPENDS+=	${PYPKGPREFIX}-pydantic>=2.7.0:../../devel/py-pydantic
TEST_DEPENDS+=	${PYPKGPREFIX}-test-examples>=0:../../devel/py-test-examples
TEST_DEPENDS+=	${PYPKGPREFIX}-test-mock>=0:../../devel/py-test-mock
#TEST_DEPENDS+=	${PYPKGPREFIX}-azure-core>=0:../../wip/py-azure-core

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
