# $NetBSD: Makefile,v 1.61 2024/02/22 11:55:59 adam Exp $

DISTNAME=	grpcio-tools-1.62.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_PYPI:=g/grpcio-tools/}

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://grpc.io/
COMMENT=	Protobuf code generator for gRPC
LICENSE=	apache-2.0

TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel
DEPENDS+=	${PYPKGPREFIX}-grpcio>=${PKGVERSION_NOREV}:../../net/py-grpcio
DEPENDS+=	${PYPKGPREFIX}-protobuf>=4.21.6:../../devel/py-protobuf
DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools

CHECK_PORTABILITY_SKIP=	third_party/protobuf/*.sh

USE_LANGUAGES=		c c++
USE_CXX_FEATURES=	c++14

MAKE_ENV+=	GRPC_PYTHON_LDFLAGS="-lprotoc ${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.protobuf}/lib"

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../devel/protobuf/buildlink3.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
