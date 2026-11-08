# $NetBSD: Makefile,v 1.1 2026/11/08 21:31:12 wiz Exp $

DISTNAME=	opentelemetry_test_utils-0.66b2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/g}
CATEGORIES=	devel net python
MASTER_SITES=	${MASTER_SITE_PYPI:=o/opentelemetry_test_utils/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/open-telemetry/opentelemetry-python/tests/opentelemetry-test-utils
COMMENT=	Test utilities for OpenTelemetry unit tests
LICENSE=	apache-2.0

TOOL_DEPENDS+=	${PYPKGPREFIX}-hatchling>=0:../../devel/py-hatchling

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
