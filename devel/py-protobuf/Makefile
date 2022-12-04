# $NetBSD: Makefile,v 1.62 2022/12/04 17:38:45 adam Exp $

DISTNAME=	protobuf-4.21.10
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/protobuf/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://developers.google.com/protocol-buffers/
COMMENT=	Python bindings for protobuf
LICENSE=	modified-bsd

USE_LANGUAGES+=	c c++11

PYTHON_VERSIONS_INCOMPATIBLE=	27

MAKE_ENV+=	PROTOC=${PREFIX}/bin/protoc
PLIST_VARS+=	cpp

.include "../../lang/python/pyversion.mk"
.if ${_PYTHON_VERSION} != 311
# As of 4.21.9, the sources do contain outdated code that only supports Python < 3.11
# https://github.com/protocolbuffers/protobuf/issues/11031#issuecomment-1321390551
# Do not use C++ implementation for Python 3.11.
PYSETUPBUILDARGS=	--cpp_implementation
PYSETUPINSTALLARGS=	--cpp_implementation
PLIST.cpp=		yes
.include "../../devel/protobuf/buildlink3.mk"
.endif

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
