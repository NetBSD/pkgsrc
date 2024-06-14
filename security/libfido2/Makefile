# $NetBSD: Makefile,v 1.15 2024/06/14 15:12:46 adam Exp $

DISTNAME=	libfido2-1.15.0
CATEGORIES=	security devel
MASTER_SITES=	https://developers.yubico.com/libfido2/Releases/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://developers.yubico.com/libfido2/
COMMENT=	U2F/FIDO/FIDO2 library and tools
LICENSE=	2-clause-bsd

# libfido2 has src/hid-foo.c for a variety of platforms, and the rest
# are unimplemented.  Upstream has an option not to use hid, but USB
# fido2 keys are the typical approach and thus far the package does
# not support that option.
BROKEN_EXCEPT_ON_PLATFORM+=	Darwin-*-*
BROKEN_EXCEPT_ON_PLATFORM+=	FreeBSD-*-* MidnightBSD-*-*
BROKEN_EXCEPT_ON_PLATFORM+=	Linux-*-*
BROKEN_EXCEPT_ON_PLATFORM+=	NetBSD-*-*
BROKEN_EXCEPT_ON_PLATFORM+=	OpenBSD-*-*

# This library does not yet support illumos, but its developers and users
# strongly value bulk build reports rather than hiding breakages.
BROKEN_EXCEPT_ON_PLATFORM+=	SunOS-*-*

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
