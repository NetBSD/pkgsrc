# $NetBSD: options.mk,v 1.1.1.1 2010/03/13 17:47:56 pettai Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.softhsm
PKG_SUPPORTED_OPTIONS=		sigver
PKG_SUGGESTED_OPTIONS=

.include "../../mk/bsd.options.mk"

###
### Signature verification for debugging
###
.if !empty(PKG_OPTIONS:Msigver)
CONFIGURE_ARGS+=	--enable-sigver
.endif
