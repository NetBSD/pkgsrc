# $NetBSD: Makefile,v 1.25 2025/02/20 12:38:32 adam Exp $

DISTNAME=	elasticsearch-8.17.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	databases python
MASTER_SITES=	${MASTER_SITE_PYPI:=e/elasticsearch/}

MAINTAINER=	imil@NetBSD.org
HOMEPAGE=	https://github.com/elastic/elasticsearch-py
COMMENT=	Python client for Elasticsearch
LICENSE=	apache-2.0

TOOL_DEPENDS+=	${PYPKGPREFIX}-hatchling-[0-9]*:../../devel/py-hatchling
DEPENDS+=	${PYPKGPREFIX}-elastic-transport>=8.15.1:../../databases/py-elastic-transport

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
