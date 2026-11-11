# $NetBSD: Makefile,v 1.1 2026/11/11 15:08:40 wiz Exp $

DISTNAME=	opentelemetry_sdk-1.45.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=o/opentelemetry_sdk/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/open-telemetry/opentelemetry-python/tree/main/opentelemetry-sdk
COMMENT=	OpenTelemetry Python SDK
LICENSE=	apache-2.0

TOOL_DEPENDS+=	${PYPKGPREFIX}-hatchling>=0:../../devel/py-hatchling
DEPENDS+=	${PYPKGPREFIX}-opentelemetry-semantic-conventions>=0:../../devel/py-opentelemetry-semantic-conventions
DEPENDS+=	${PYPKGPREFIX}-typing-extensions>=4.5.0:../../devel/py-typing-extensions
TEST_DEPENDS+=	${PYPKGPREFIX}-opentelemetry-test-utils>=0:../../devel/py-opentelemetry-test-utils

USE_LANGUAGES=	# none

TEST_ENV+=	PYTHONPATH=${WRKSRC}/src

# as of 1.45.2
# 15 failed, 914 passed, 3 skipped, 69 warnings

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
