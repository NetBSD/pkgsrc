# $NetBSD: Makefile,v 1.61 2023/11/02 12:46:44 wiz Exp $

DISTNAME=	grpcio-1.59.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_PYPI:=g/grpcio/}

MAINTAINER=	kethzer.dr@gmail.com
HOMEPAGE=	https://grpc.io/
COMMENT=	HTTP/2-based RPC framework
LICENSE=	apache-2.0

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel

PYTHON_VERSIONS_INCOMPATIBLE=	27

USE_LANGUAGES=	c99 c++11
USE_TOOLS+=	gmake pkg-config

.include "../../devel/abseil/buildlink3.mk"
.include "../../devel/re2/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../net/grpc/buildlink3.mk"
.include "../../net/libcares/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
