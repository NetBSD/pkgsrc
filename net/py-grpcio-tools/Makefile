# $NetBSD: Makefile,v 1.1 2018/04/28 01:24:36 minskim Exp $

DISTNAME=	grpcio-tools-1.11.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_PYPI:=g/grpcio-tools/}

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://grpc.io/
COMMENT=	Protobuf code generator for gRPC
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-grpcio>=1.11.0:../../net/py-grpcio
DEPENDS+=	${PYPKGPREFIX}-protobuf>=3.5.0:../../devel/py-protobuf

USE_LANGUAGES=	c c++11

.include "../../lang/python/egg.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
