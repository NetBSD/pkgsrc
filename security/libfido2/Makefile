# $NetBSD: Makefile,v 1.10 2023/10/24 22:10:50 wiz Exp $

DISTNAME=	libfido2-1.13.0
PKGREVISION=	1
CATEGORIES=	security devel
MASTER_SITES=	https://developers.yubico.com/libfido2/Releases/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://developers.yubico.com/libfido2/
COMMENT=	U2F/FIDO/FIDO2 library and tools
LICENSE=	2-clause-bsd

USE_LANGUAGES=		c
USE_TOOLS+=		pkg-config mandoc
CMAKE_ARGS+=		-DBUILD_EXAMPLES=OFF
CMAKE_ARGS.NetBSD+=	-DBASE_LIBRARIES:STRING=usbhid
TEST_TARGET=		test

CHECK_PORTABILITY_SKIP+=	misc/hooks

.include "../../devel/cmake/build.mk"
.include "../../devel/libcbor/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.fast.prefs.mk"
.if ${OPSYS} == "Linux"
.  include "../../sysutils/libudev/buildlink3.mk"
.endif
.include "../../mk/bsd.pkg.mk"
