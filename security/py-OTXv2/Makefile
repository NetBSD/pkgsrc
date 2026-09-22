# $NetBSD: Makefile,v 1.3 2026/09/22 04:40:03 adam Exp $

DISTNAME=	OTXv2-1.5.12
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	security python
MASTER_SITES=	${MASTER_SITE_PYPI:=O/OTXv2/}

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://github.com/AlienVault-Labs/OTX-Python-SDK
COMMENT=	Python SDK for AlienVault OTX
LICENSE=	apache-2.0

WHEEL_NAME=	${DISTNAME:tl}

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-dateutil>=0:../../time/py-dateutil
DEPENDS+=	${PYPKGPREFIX}-requests>=0:../../devel/py-requests
DEPENDS+=	${PYPKGPREFIX}-pytz>=0:../../time/py-pytz

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
