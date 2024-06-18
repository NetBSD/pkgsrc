# $NetBSD: Makefile,v 1.23 2024/06/18 12:32:37 adam Exp $

DISTNAME=	elasticsearch-8.14.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	databases python
MASTER_SITES=	${MASTER_SITE_PYPI:=e/elasticsearch/}

MAINTAINER=	imil@NetBSD.org
HOMEPAGE=	https://github.com/elastic/elasticsearch-py
COMMENT=	Python client for Elasticsearch
LICENSE=	apache-2.0

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel
DEPENDS+=	${PYPKGPREFIX}-elastic-transport>=8.13:../../databases/py-elastic-transport

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
