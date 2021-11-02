# $NetBSD: Makefile,v 1.39 2021/11/02 11:43:02 adam Exp $

DISTNAME=	grpcio-1.41.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_PYPI:=g/grpcio/}

MAINTAINER=	kethzer.dr@gmail.com
HOMEPAGE=	https://grpc.io/
COMMENT=	HTTP/2-based RPC framework
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-six>=1.5.2:../../lang/py-six

PYTHON_VERSIONS_INCOMPATIBLE=	27

USE_LANGUAGES=	c99 c++11
USE_TOOLS+=	gmake pkg-config

.include "../../devel/abseil/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../net/grpc/buildlink3.mk"
.include "../../net/libcares/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
