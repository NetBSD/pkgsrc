# $NetBSD: Makefile,v 1.3 2014/06/06 12:48:35 joerg Exp $

DISTNAME=	apache-libcloud-0.14.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
EGG_NAME=	${DISTNAME:S,-,_,}
CATEGORIES=	net
MASTER_SITES=	https://pypi.python.org/packages/source/a/apache-libcloud/

MAINTAINER=	imil@NetBSD.org
HOMEPAGE=	https://libcloud.apache.org/
COMMENT=	Python library for interacting with cloud service providers
LICENSE=	apache-2.0

USE_LANGUAGES=	# none

DEPENDS+=	${PYPKGPREFIX}-simplejson>=3.3.2:../../converters/py-simplejson

.include "../../lang/python/egg.mk"

.if !empty(_PYTHON_VERSION:M3*)
DEPENDS+=	${PYPKGPREFIX}-expat-[0-9]*:../../textproc/py-expat
.endif

.include "../../mk/bsd.pkg.mk"
