# $NetBSD: Makefile,v 1.2 2016/06/08 17:43:22 wiz Exp $

DISTNAME=	pymongo-2.7.1
PKGNAME=	${DISTNAME:S/py/${PYPKGPREFIX}-/1}
CATEGORIES=	databases python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pymongo/}

MAINTAINER=	mishka@NetBSD.org
HOMEPAGE=	http://github.com/mongodb/mongo-python-driver
COMMENT=	Python driver for MongoDB
LICENSE=	apache-2.0

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
