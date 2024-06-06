# $NetBSD: Makefile,v 1.73 2024/06/06 18:58:45 adam Exp $

DISTNAME=	protobuf-5.27.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/protobuf/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://developers.google.com/protocol-buffers/
COMMENT=	Python bindings for protobuf
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel

USE_CXX_FEATURES=	c++11
USE_LANGUAGES+=		c c++

PYTHON_VERSIONS_INCOMPATIBLE=	27

MAKE_ENV+=	PROTOC=${PREFIX}/bin/protoc

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
