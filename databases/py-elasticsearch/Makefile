# $NetBSD: Makefile,v 1.8 2016/01/07 16:09:02 fhajny Exp $

DISTNAME=	elasticsearch-py-2.2.0
PKGNAME=	${PYPKGPREFIX}-${EGG_NAME}
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_GITHUB:=elastic/}

MAINTAINER=	imil@NetBSD.org
HOMEPAGE=	http://github.com/elastic/elasticsearch-py/
COMMENT=	Official low-level python client for Elasticsearch
LICENSE=	apache-2.0

EGG_NAME=	${DISTNAME:S/-py//}
GITHUB_PROJECT=	elasticsearch-py

USE_LANGUAGES=	# none

DEPENDS+=	${PYPKGPREFIX}-urllib3>=1.8.2:../../www/py-urllib3

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
