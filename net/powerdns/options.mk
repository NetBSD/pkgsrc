# $NetBSD: options.mk,v 1.1 2014/12/10 14:50:08 fhajny Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.powerdns
PKG_SUPPORTED_OPTIONS=	bind botan pipe random remote sqlite tools
PKG_SUGGESTED_OPTIONS=	bind pipe random

.include "../../mk/bsd.options.mk"

PLIST_VARS+=		bind pipe random remote sqlite tools

.if !empty(PKG_OPTIONS:Mbind)
PDNS_MODULES+=		bind
PLIST.bind=		yes
.endif

.if !empty(PKG_OPTIONS:Mbotan)
CONFIGURE_ARGS+=	--enable-botan1.8
.include "../../security/botan/buildlink3.mk"
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
