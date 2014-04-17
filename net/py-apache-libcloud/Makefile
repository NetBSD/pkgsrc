# $NetBSD: Makefile,v 1.1 2014/04/17 16:23:30 imil Exp $

DISTNAME=	apache-libcloud-0.14.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	net
MASTER_SITES=	https://pypi.python.org/packages/source/a/apache-libcloud/

MAINTAINER=	imil@NetBSD.org
HOMEPAGE=	https://libcloud.apache.org/
COMMENT=	Python library for interacting with cloud service providers
LICENSE=	apache-2.0

USE_LANGUAGES=	# none

DEPENDS+=	${PYPKGPREFIX}-simplejson>=3.3.2:../../converters/py-simplejson

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
