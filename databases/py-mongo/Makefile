# $NetBSD: Makefile,v 1.19 2024/04/02 18:27:51 adam Exp $

DISTNAME=	pymongo-4.6.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/^py//}
CATEGORIES=	databases python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pymongo/}

MAINTAINER=	mishka@NetBSD.org
HOMEPAGE=	https://github.com/mongodb/mongo-python-driver
COMMENT=	Python driver for MongoDB
LICENSE=	apache-2.0

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=63.0:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel
DEPENDS+=	${PYPKGPREFIX}-dns>=1.16.0:../../net/py-dns

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
