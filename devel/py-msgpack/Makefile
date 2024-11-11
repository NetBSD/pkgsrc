# $NetBSD: Makefile,v 1.36 2024/11/11 07:28:16 wiz Exp $

DISTNAME=	msgpack-1.1.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=m/msgpack/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/msgpack/msgpack-python
COMMENT=	MessagePack (de)serializer for Python
LICENSE=	apache-2.0

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=69.5.1:../../devel/py-setuptools

USE_LANGUAGES=	c c++

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
