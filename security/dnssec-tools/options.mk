# $NetBSD: options.mk,v 1.2 2012/06/12 15:46:03 wiz Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.dnssec-tools
PKG_SUPPORTED_OPTIONS=		inet6 dlv
PKG_SUGGESTED_OPTIONS=		inet6

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Minet6)
CONFIGURE_ARGS+=	--with-ipv6
.else
CONFIGURE_ARGS+=	--without-ipv6
.endif

###
### DLV support
###
.if !empty(PKG_OPTIONS:Mdlv)
CONFIGURE_ARGS+=	--with-dlv
.else
CONFIGURE_ARGS+=	--without-dlv
.endif
