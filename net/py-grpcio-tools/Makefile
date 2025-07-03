# $NetBSD: Makefile,v 1.85 2025/07/03 06:28:34 wiz Exp $

DISTNAME=	grpcio_tools-1.73.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/}
PKGREVISION=	1
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_PYPI:=g/grpcio-tools/}

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://grpc.io/
COMMENT=	Protobuf code generator for gRPC
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-grpcio>=${PKGVERSION_NOREV}:../../net/py-grpcio
DEPENDS+=	${PYPKGPREFIX}-protobuf>=5.26.1:../../devel/py-protobuf
DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools

CHECK_PORTABILITY_SKIP=	third_party/protobuf/*.sh

USE_CXX_FEATURES=	c++17
USE_LANGUAGES=		c c++

MAKE_ENV+=	GRPC_PYTHON_LDFLAGS="-lprotoc ${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.protobuf}/lib"

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} python-grpc-tools-protoc python-grpc-tools-protoc-${PYVERSSUFFIX} || ${TRUE}

.include "../../devel/protobuf/buildlink3.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
