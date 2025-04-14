# $NetBSD: Makefile,v 1.21 2025/04/14 11:31:11 adam Exp $

DISTNAME=	pymongo-4.6.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/^py//}
PKGREVISION=	1
CATEGORIES=	databases python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pymongo/}

MAINTAINER=	mishka@NetBSD.org
HOMEPAGE=	https://github.com/mongodb/mongo-python-driver
COMMENT=	Python driver for MongoDB
LICENSE=	apache-2.0

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-dns>=1.16.0:../../net/py-dns

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
