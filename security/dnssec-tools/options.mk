# $NetBSD: options.mk,v 1.1.1.1 2010/07/22 21:08:26 pettai Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.dnssec-tools
PKG_SUPPORTED_OPTIONS=		inet6 dlv
PKG_SUGGESTED_OPTIONS=

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
