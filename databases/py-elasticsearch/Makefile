# $NetBSD: Makefile,v 1.3 2015/03/09 15:56:33 imil Exp $

DISTNAME=	elasticsearch-1.4.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	databases
MASTER_SITES=	https://pypi.python.org/packages/source/e/elasticsearch/

MAINTAINER=	imil@NetBSD.org
HOMEPAGE=	http://www.elasticsearch.org/guide/en/elasticsearch/client/python-api/current/
COMMENT=	Official low-level python client for Elasticsearch
LICENSE=	apache-2.0

USE_LANGUAGES=	# none

DEPENDS+=	${PYPKGPREFIX}-urllib3>=1.8.2:../../www/py-urllib3

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
