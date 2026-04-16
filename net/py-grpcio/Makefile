# $NetBSD: Makefile,v 1.104 2026/04/16 09:58:01 adam Exp $

DISTNAME=	grpcio-1.80.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_PYPI:=g/grpcio/}

MAINTAINER=	kethzer.dr@gmail.com
HOMEPAGE=	https://grpc.io/
COMMENT=	HTTP/2-based RPC framework
LICENSE=	apache-2.0

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools

USE_CC_FEATURES=	c99
USE_CXX_FEATURES=	c++17
FORCE_CXX_STD=		c++17
USE_LANGUAGES=		c c++
USE_TOOLS+=		gmake pkg-config

MAKE_ENV+=	GRPC_PYTHON_BUILD_EXT_COMPILER_JOBS=${_MAKE_JOBS_N:U1}
MAKE_ENV+=	GRPC_PYTHON_BUILD_SYSTEM_ABSL=1
MAKE_ENV+=	GRPC_PYTHON_BUILD_SYSTEM_CARES=1
MAKE_ENV+=	GRPC_PYTHON_BUILD_SYSTEM_OPENSSL=1
MAKE_ENV+=	GRPC_PYTHON_BUILD_SYSTEM_RE2=1
MAKE_ENV+=	GRPC_PYTHON_BUILD_SYSTEM_ZLIB=1

pre-test:
	${RM} -f ${WRKSRC}/third_party/boringssl-with-bazel/src/third_party/googletest/googlemock/test/*py
	${RM} -f ${WRKSRC}/third_party/boringssl-with-bazel/src/third_party/googletest/googletest/test/*py
	${RM} -f ${WRKSRC}/third_party/upb/upb/cmake/*.py

.include "../../devel/abseil/buildlink3.mk"
.include "../../devel/re2/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../net/libcares/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
