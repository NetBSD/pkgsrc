# $NetBSD: Makefile,v 1.12 2021/10/20 19:47:22 adam Exp $

DISTNAME=	pymongo-3.12.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/^py//}
CATEGORIES=	databases python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pymongo/}

MAINTAINER=	mishka@NetBSD.org
HOMEPAGE=	https://github.com/mongodb/mongo-python-driver
COMMENT=	Python driver for MongoDB
LICENSE=	apache-2.0

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
