# $NetBSD: Makefile,v 1.13 2026/10/13 12:42:45 adam Exp $

DISTNAME=	absl_py-2.5.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=a/absl-py/}

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://github.com/abseil/abseil-py
COMMENT=	Abseil Python Common Libraries
LICENSE=	apache-2.0

TOOL_DEPENDS+=	${PYPKGPREFIX}-hatchling>=1.26:../../devel/py-hatchling

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
