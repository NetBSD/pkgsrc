# $NetBSD: Makefile,v 1.6 2022/08/05 20:22:05 adam Exp $

DISTNAME=	libfido2-1.11.0
CATEGORIES=	security devel
MASTER_SITES=	https://developers.yubico.com/libfido2/Releases/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://developers.yubico.com/libfido2/
COMMENT=	U2F/FIDO/FIDO2 library and tools
LICENSE=	2-clause-bsd

USE_CMAKE=		yes
USE_LANGUAGES=		c
USE_TOOLS+=		pkg-config
CONFIGURE_DIRS+=	build
CMAKE_ARG_PATH=		..
CMAKE_ARGS.NetBSD+=	-DBASE_LIBRARIES:STRING=usbhid
TEST_TARGET=		test

CHECK_PORTABILITY_SKIP+=	misc/hooks

pre-configure:
	${MKDIR} ${WRKSRC}/build

.include "../../devel/libcbor/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
