# $NetBSD: Makefile,v 1.4 2026/11/16 16:20:23 adam Exp $

DISTNAME=	u_msgpack_python-2.9.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/:S/_python//}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=u/u-msgpack-python/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/vsergeev/u-msgpack-python
COMMENT=	MessagePack serializer and deserializer written in pure Python
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
