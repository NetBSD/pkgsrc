# $NetBSD: Makefile,v 1.39 2025/04/12 12:08:14 adam Exp $

DISTNAME=	msgpack-1.1.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=m/msgpack/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/msgpack/msgpack-python
COMMENT=	MessagePack (de)serializer for Python
LICENSE=	apache-2.0

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools

USE_LANGUAGES=	c c++

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
