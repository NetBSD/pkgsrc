# $NetBSD: Makefile,v 1.1 2018/04/28 01:16:29 minskim Exp $

DISTNAME=	grpcio-1.11.0
PKGNAME=        ${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	net
MASTER_SITES=   ${MASTER_SITE_PYPI:=g/grpcio/}

MAINTAINER=	kethzer.dr@gmail.com
HOMEPAGE=	https://grpc.io/
COMMENT=	HTTP/2-based RPC framework
LICENSE=	apache-2.0

DEPENDS+=       ${PYPKGPREFIX}-protobuf>=3.5.0:../../devel/py-protobuf
DEPENDS+=       ${PYPKGPREFIX}-six>=1.5.2:../../lang/py-six

.include "../../lang/python/pyversion.mk"
.if "${PYPKGPREFIX}" == "py27"
DEPENDS+=       ${PYPKGPREFIX}-enum34>=1.0.4:../../devel/py-enum34
DEPENDS+=       ${PYPKGPREFIX}-futures>=2.2.0:../../devel/py-futures
.endif

USE_LANGUAGES+=	c99 c++11
USE_TOOLS+=	gmake pkg-config

.include "../../devel/zlib/buildlink3.mk"
.include "../../net/grpc/buildlink3.mk"
.include "../../net/libcares/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
