# $NetBSD: Makefile,v 1.92 2025/12/21 13:08:56 adam Exp $

DISTNAME=	protobuf-6.33.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/protobuf/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://developers.google.com/protocol-buffers/
COMMENT=	Python bindings for protobuf
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools

USE_CXX_FEATURES=	c++11
USE_LANGUAGES+=		c c++

MAKE_ENV+=	PROTOC=${PREFIX}/bin/protoc

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
