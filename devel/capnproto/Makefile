# $NetBSD: Makefile,v 1.6 2025/02/07 10:54:20 wiz Exp $

DISTNAME=	capnproto-c++-1.1.0
PKGNAME=	${DISTNAME:S/-c++-/-/}
CATEGORIES=	devel
MASTER_SITES=	https://capnproto.org/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://capnproto.org/
COMMENT=	Cap'n Proto - Insanely Fast Data Serialization Format
LICENSE=	mit

USE_CXX_FEATURES=	c++14
USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
USE_TOOLS+=		pkg-config
GNU_CONFIGURE=		yes
# Fibers are not supported on BSD platforms: see src/kj/async.h
CONFIGURE_ARGS+=	--without-fibers
TEST_TARGET=		check

# Requires EVFILT_USER, unavailable on NetBSD 9.x and prior
NOT_FOR_PLATFORM+=	NetBSD-[0-9].*-*

PKGCONFIG_OVERRIDE+=	pkgconfig/capnp-json.pc.in
PKGCONFIG_OVERRIDE+=	pkgconfig/capnp-rpc.pc.in
PKGCONFIG_OVERRIDE+=	pkgconfig/capnp-websocket.pc
PKGCONFIG_OVERRIDE+=	pkgconfig/capnp.pc.in
PKGCONFIG_OVERRIDE+=	pkgconfig/capnpc.pc.in
PKGCONFIG_OVERRIDE+=	pkgconfig/kj-async.pc.in
PKGCONFIG_OVERRIDE+=	pkgconfig/kj-gzip.pc.in
PKGCONFIG_OVERRIDE+=	pkgconfig/kj-http.pc.in
PKGCONFIG_OVERRIDE+=	pkgconfig/kj-test.pc.in
PKGCONFIG_OVERRIDE+=	pkgconfig/kj-tls.pc.in
PKGCONFIG_OVERRIDE+=	pkgconfig/kj.pc.in

.include "../../devel/zlib/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
