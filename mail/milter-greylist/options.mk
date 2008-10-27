# $NetBSD: options.mk,v 1.5 2008/10/27 19:40:11 tron Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.milter-greylist
PKG_SUPPORTED_OPTIONS=		dnsrbl drac spf
PKG_SUGGESTED_OPTIONS=		dnsrbl spf

.include "../../mk/bsd.options.mk"

###
### DNS Realtime Black List
###
.if !empty(PKG_OPTIONS:Mdnsrbl)
CONFIGURE_ARGS+=	--enable-dnsrbl --with-thread-safe-resolver
.endif

###
### Dynamic Relay Authorization Control
###
.if empty(PKG_OPTIONS:Mdrac)
CONFIGURE_ARGS+=	--disable-drac
.else
DRACD_DB?=		/etc/mail/dracd.db

CONFIGURE_ARGS+=	--enable-drac --with-drac-db=${DRACD_DB}
.endif

###
### Sender Policy Framework
###
.if empty(PKG_OPTIONS:Mspf)
CONFIGURE_ARGS+=	--disable-libspf2
.else
.include "../../mail/libspf2/buildlink3.mk"

CONFIGURE_ARGS+=	--with-libspf2=${PREFIX:Q}
.endif
