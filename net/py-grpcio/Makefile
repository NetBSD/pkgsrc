# $NetBSD: Makefile,v 1.86 2024/11/05 17:22:00 wiz Exp $

DISTNAME=	grpcio-1.67.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_PYPI:=g/grpcio/}

MAINTAINER=	kethzer.dr@gmail.com
HOMEPAGE=	https://grpc.io/
COMMENT=	HTTP/2-based RPC framework
LICENSE=	apache-2.0

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel

USE_CC_FEATURES=	c99
USE_CXX_FEATURES=	c++14
USE_LANGUAGES=		c c++
USE_TOOLS+=		gmake pkg-config

pre-test:
	${RM} -f ${WRKSRC}/third_party/boringssl-with-bazel/src/third_party/googletest/googlemock/test/*py
	${RM} -f ${WRKSRC}/third_party/boringssl-with-bazel/src/third_party/googletest/googletest/test/*py
	${RM} -f ${WRKSRC}/third_party/upb/upb/cmake/*.py

.include "../../devel/abseil/buildlink3.mk"
.include "../../devel/re2/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../net/grpc/buildlink3.mk"
.include "../../net/libcares/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
