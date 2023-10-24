# $NetBSD: Makefile,v 1.4 2023/10/24 22:08:42 wiz Exp $

DISTNAME=	capnproto-c++-0.8.0
PKGNAME=	${DISTNAME:S/capnproto-c++-/capnproto-/}
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	https://capnproto.org/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://capnproto.org/
COMMENT=	Cap'n Proto - Insanely Fast Data Serialization Format
LICENSE=	mit

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++

USE_CXX_FEATURES+=	c++14

PKGCONFIG_OVERRIDE+=	pkgconfig/capnp-json.pc.in
PKGCONFIG_OVERRIDE+=	pkgconfig/capnp-rpc.pc.in
PKGCONFIG_OVERRIDE+=	pkgconfig/capnp.pc.in
PKGCONFIG_OVERRIDE+=	pkgconfig/kj-async.pc.in
PKGCONFIG_OVERRIDE+=	pkgconfig/kj-gzip.pc.in
PKGCONFIG_OVERRIDE+=	pkgconfig/kj-http.pc.in
PKGCONFIG_OVERRIDE+=	pkgconfig/kj-test.pc.in
PKGCONFIG_OVERRIDE+=	pkgconfig/kj-tls.pc.in
PKGCONFIG_OVERRIDE+=	pkgconfig/kj.pc.in

.include "../../devel/zlib/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
