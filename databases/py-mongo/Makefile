# $NetBSD: Makefile,v 1.14 2023/07/29 11:42:36 adam Exp $

DISTNAME=	pymongo-4.4.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/^py//}
CATEGORIES=	databases python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pymongo/}

MAINTAINER=	mishka@NetBSD.org
HOMEPAGE=	https://github.com/mongodb/mongo-python-driver
COMMENT=	Python driver for MongoDB
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-dns>=1.16.0:../../net/py-dns

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
