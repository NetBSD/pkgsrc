# $NetBSD: Makefile,v 1.6 2019/05/26 19:50:12 adam Exp $

DISTNAME=	grpcio-1.21.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_PYPI:=g/grpcio/}

MAINTAINER=	kethzer.dr@gmail.com
HOMEPAGE=	https://grpc.io/
COMMENT=	HTTP/2-based RPC framework
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-protobuf>=3.5.0:../../devel/py-protobuf
DEPENDS+=	${PYPKGPREFIX}-six>=1.5.2:../../lang/py-six

.include "../../lang/python/pyversion.mk"
.if ${_PYTHON_VERSION} == 27
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
