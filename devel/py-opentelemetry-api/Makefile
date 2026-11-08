# $NetBSD: Makefile,v 1.1 2026/11/08 21:31:51 wiz Exp $

DISTNAME=	opentelemetry_api-1.45.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=o/opentelemetry_api/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/open-telemetry/opentelemetry-python/tree/main/opentelemetry-api
COMMENT=	OpenTelemetry Python API
LICENSE=	apache-2.0

TOOL_DEPENDS+=	${PYPKGPREFIX}-hatchling>=0:../../devel/py-hatchling
DEPENDS+=	${PYPKGPREFIX}-typing-extensions>=4.5.0:../../devel/py-typing-extensions
TEST_DEPENDS+=	${PYPKGPREFIX}-opentelemetry-test-utils>=0:../../devel/py-opentelemetry-test-utils

USE_LANGUAGES=	# none

TEST_ENV+=	PYTHONPATH=${WRKSRC}/src

# as of 1.45.2
# 4 failed, 284 passed, 1 skipped

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
