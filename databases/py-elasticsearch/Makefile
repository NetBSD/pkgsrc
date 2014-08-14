# $NetBSD: Makefile,v 1.2 2014/08/14 16:53:00 imil Exp $

DISTNAME=	elasticsearch-1.2.0
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
