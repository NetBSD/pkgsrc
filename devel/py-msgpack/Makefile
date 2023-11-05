# $NetBSD: Makefile,v 1.33 2023/11/05 11:09:14 wiz Exp $

DISTNAME=	msgpack-1.0.7
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=m/msgpack/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://msgpack.org/
COMMENT=	MessagePack (de)serializer for Python
LICENSE=	apache-2.0

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel

PYTHON_VERSIONS_INCOMPATIBLE=	27

USE_LANGUAGES=	c c++

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
