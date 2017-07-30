# $NetBSD: Makefile,v 1.3 2017/07/30 22:32:11 wiz Exp $

DISTNAME=	pymongo-2.7.1
PKGNAME=	${DISTNAME:S/py/${PYPKGPREFIX}-/1}
CATEGORIES=	databases python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pymongo/}

MAINTAINER=	mishka@NetBSD.org
HOMEPAGE=	https://github.com/mongodb/mongo-python-driver
COMMENT=	Python driver for MongoDB
LICENSE=	apache-2.0

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
