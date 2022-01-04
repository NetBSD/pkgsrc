# $NetBSD: Makefile,v 1.17 2022/01/04 20:52:42 wiz Exp $

DISTNAME=	elasticsearch-py-6.2.0
PKGNAME=	${PYPKGPREFIX}-${EGG_NAME}
PKGREVISION=	1
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_GITHUB:=elastic/}

MAINTAINER=	imil@NetBSD.org
HOMEPAGE=	https://github.com/elastic/elasticsearch-py/
COMMENT=	Official low-level python client for Elasticsearch
LICENSE=	apache-2.0

EGG_NAME=	${DISTNAME:S/-py//}
GITHUB_PROJECT=	elasticsearch-py

USE_LANGUAGES=	# none

DEPENDS+=	${PYPKGPREFIX}-urllib3>=1.21.1:../../www/py-urllib3

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
