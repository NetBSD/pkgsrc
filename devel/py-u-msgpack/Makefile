# $NetBSD: Makefile,v 1.3 2025/04/12 21:37:06 adam Exp $

DISTNAME=	u-msgpack-python-2.8.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/-python//}
PKGREVISION=	1
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
