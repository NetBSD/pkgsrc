# $NetBSD: Makefile,v 1.54 2023/11/02 12:20:05 wiz Exp $

DISTNAME=	grpcio-tools-1.54.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_PYPI:=g/grpcio-tools/}

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://grpc.io/
COMMENT=	Protobuf code generator for gRPC
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-grpcio>=${PKGVERSION_NOREV}:../../net/py-grpcio
DEPENDS+=	${PYPKGPREFIX}-protobuf>=4.21.6:../../devel/py-protobuf

CHECK_PORTABILITY_SKIP=	third_party/protobuf/*.sh

USE_LANGUAGES=	c c++11
MAKE_ENV+=	GRPC_PYTHON_LDFLAGS="-lprotoc ${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.protobuf}/lib"

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../devel/protobuf/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
