# $NetBSD: Makefile,v 1.7 2023/03/15 14:38:13 adam Exp $

DISTNAME=	libfido2-1.13.0
CATEGORIES=	security devel
MASTER_SITES=	https://developers.yubico.com/libfido2/Releases/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://developers.yubico.com/libfido2/
COMMENT=	U2F/FIDO/FIDO2 library and tools
LICENSE=	2-clause-bsd

USE_LANGUAGES=		c
USE_TOOLS+=		pkg-config
CMAKE_ARGS+=		-DBUILD_EXAMPLES=OFF
CMAKE_ARGS.NetBSD+=	-DBASE_LIBRARIES:STRING=usbhid
TEST_TARGET=		test

CHECK_PORTABILITY_SKIP+=	misc/hooks

.include "../../devel/cmake/build.mk"
.include "../../devel/libcbor/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
