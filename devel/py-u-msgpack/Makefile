# $NetBSD: Makefile,v 1.1 2024/04/30 08:55:30 wiz Exp $

DISTNAME=	u-msgpack-python-2.8.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/-python//}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=u/u-msgpack-python/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/vsergeev/u-msgpack-python
COMMENT=	MessagePack serializer and deserializer written in pure Python
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
