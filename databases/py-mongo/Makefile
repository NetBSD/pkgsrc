# $NetBSD: Makefile,v 1.13 2022/01/04 20:52:42 wiz Exp $

DISTNAME=	pymongo-3.12.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/^py//}
PKGREVISION=	1
CATEGORIES=	databases python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pymongo/}

MAINTAINER=	mishka@NetBSD.org
HOMEPAGE=	https://github.com/mongodb/mongo-python-driver
COMMENT=	Python driver for MongoDB
LICENSE=	apache-2.0

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
