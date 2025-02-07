# $NetBSD: Makefile,v 1.8 2025/02/07 13:19:30 riastradh Exp $

DISTNAME=	capnproto-c++-1.1.0
PKGNAME=	${DISTNAME:S/-c++-/-/}
PKGREVISION=	1
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

.include "../../mk/bsd.prefs.mk"

# When kqueue is enabled (default yes on *BSD), this requires
# EVFILT_USER, which in NetBSD was only introduced in 10.0.  So
# explicitly disable kqueue for NetBSD<10.
.if ${OPSYS} == "NetBSD" && ${OPSYS_VERSION} < 100000
CPPFLAGS+=		-DKJ_USE_KQUEUE=0
.endif

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
