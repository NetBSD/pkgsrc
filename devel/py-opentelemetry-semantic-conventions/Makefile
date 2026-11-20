# $NetBSD: Makefile,v 1.2 2026/11/20 12:59:50 adam Exp $

DISTNAME=	opentelemetry_semantic_conventions-0.66b2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/g}
CATEGORIES=	devel net python
MASTER_SITES=	${MASTER_SITE_PYPI:=o/opentelemetry-semantic-conventions/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/open-telemetry/opentelemetry-python/tree/main/opentelemetry-semantic-conventions
COMMENT=	OpenTelemetry Semantic Conventions
LICENSE=	apache-2.0

TOOL_DEPENDS+=	${PYPKGPREFIX}-hatchling>=0:../../devel/py-hatchling
DEPENDS+=	${PYPKGPREFIX}-opentelemetry-api>=0:../../devel/py-opentelemetry-api

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
