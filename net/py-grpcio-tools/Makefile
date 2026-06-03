# $NetBSD: Makefile,v 1.94 2026/06/03 07:54:15 adam Exp $

DISTNAME=	grpcio_tools-1.81.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/}
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_PYPI:=g/grpcio-tools/}

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://grpc.io/
COMMENT=	Protobuf code generator for gRPC
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-grpcio>=${PKGVERSION_NOREV}:../../net/py-grpcio
DEPENDS+=	${PYPKGPREFIX}-protobuf>=6.33.5:../../devel/py-protobuf
DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools

CHECK_PORTABILITY_SKIP=	third_party/protobuf/*.sh

USE_CXX_FEATURES=	c++17
USE_LANGUAGES=		c c++
FORCE_CXX_STD=		c++17

MAKE_ENV+=	GRPC_PYTHON_LDFLAGS="-lprotoc ${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.protobuf}/lib"

PY_RENAME_BINARIES=	python-grpc-tools-protoc

.include "../../devel/protobuf/buildlink3.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
