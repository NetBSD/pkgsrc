# $NetBSD: Makefile,v 1.5 2018/10/07 07:33:42 adam Exp $

DISTNAME=	pymongo-3.7.1
PKGNAME=	${DISTNAME:S/py/${PYPKGPREFIX}-/1}
CATEGORIES=	databases python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pymongo/}

MAINTAINER=	mishka@NetBSD.org
HOMEPAGE=	https://github.com/mongodb/mongo-python-driver
COMMENT=	Python driver for MongoDB
LICENSE=	apache-2.0

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
