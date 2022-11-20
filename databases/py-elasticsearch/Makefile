# $NetBSD: Makefile,v 1.19 2022/11/20 23:23:19 adam Exp $

DISTNAME=	elasticsearch-8.5.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	databases python
MASTER_SITES=	${MASTER_SITE_PYPI:=e/elasticsearch/}

MAINTAINER=	imil@NetBSD.org
HOMEPAGE=	https://github.com/elastic/elasticsearch-py
COMMENT=	Python client for Elasticsearch
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-elastic-transport>=8:../../databases/py-elastic-transport

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
