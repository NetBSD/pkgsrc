# $NetBSD: Makefile,v 1.56 2022/07/27 06:43:56 adam Exp $

DISTNAME=	protobuf-4.21.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/protobuf/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://developers.google.com/protocol-buffers/
COMMENT=	Python bindings for protobuf
LICENSE=	modified-bsd

USE_LANGUAGES+=	c c++11

PYTHON_VERSIONS_INCOMPATIBLE=   27

MAKE_ENV+=		PROTOC=${PREFIX}/bin/protoc
PYSETUPBUILDARGS=	--cpp_implementation
PYSETUPINSTALLARGS=	--cpp_implementation

.include "../../devel/protobuf/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
