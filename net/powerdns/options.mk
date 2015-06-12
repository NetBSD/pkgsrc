# $NetBSD: options.mk,v 1.3 2015/06/12 10:50:58 fhajny Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.powerdns
PKG_SUPPORTED_OPTIONS=	bind botan cryptopp pipe random remote sqlite tools
PKG_SUPPORTED_OPTIONS+=	zeromq
PKG_SUGGESTED_OPTIONS=	bind pipe random

.include "../../mk/bsd.options.mk"

PLIST_VARS+=		bind pipe random remote sqlite tools

.if !empty(PKG_OPTIONS:Mbind)
PDNS_MODULES+=		bind
PLIST.bind=		yes
.endif

.if !empty(PKG_OPTIONS:Mbotan)
CONFIGURE_ARGS+=	--enable-botan1.8
.include "../../devel/gmp/buildlink3.mk"
.include "../../security/botan/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mcryptopp)
.include "../../security/crypto++/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-cryptopp=yes
CRYPTOPP_CFLAGS=	-I${BUILDLINK_PREFIX.cryptopp}/include
CRYPTOPP_LIBS=		-L${BUILDLINK_PREFIX.cryptopp}/lib -Wl,-R${BUILDLINK_PREFIX.cryptopp}/lib -lcryptopp
CONFIGURE_ENV+=		CRYPTOPP_CFLAGS=${CRYPTOPP_CFLAGS:Q}
CONFIGURE_ENV+=		CRYPTOPP_LIBS=${CRYPTOPP_LIBS:Q}
.else
CONFIGURE_ARGS+=	--enable-cryptopp=no
.endif

.if !empty(PKG_OPTIONS:Mpipe)
PLIST.pipe=		yes
PDNS_MODULES+=		pipe
.endif

.if !empty(PKG_OPTIONS:Mrandom)
PLIST.random=		yes
PDNS_MODULES+=		random
.endif

.if !empty(PKG_OPTIONS:Mremote)
PLIST.remote=		yes
PDNS_MODULES+=		remote
.endif

.if !empty(PKG_OPTIONS:Msqlite)
PDNS_MODULES+=		gsqlite3
PLIST.sqlite=		yes
.include "../../databases/sqlite3/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mtools)
CONFIGURE_ARGS+=	--enable-tools
PLIST.tools=		yes
.endif

.if !empty(PKG_OPTIONS:Mzeromq)
.include "../../net/zeromq/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-remotebackend-zeromq=yes
.else
CONFIGURE_ARGS+=	--enable-remotebackend-zeromq=no
.endif
