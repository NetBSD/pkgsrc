# $NetBSD: options.mk,v 1.2 2015/06/06 17:11:43 youri Exp $
#
PKG_OPTIONS_VAR=	PKG_OPTIONS.rlwrap
PKG_SUPPORTED_OPTIONS=	debug
PKG_SUGGESTED_OPTIONS=	# empty

.include "../../mk/bsd.options.mk"

###
### debug option
###

.if !empty(PKG_OPTIONS:Mdebug)
CONFIGURE_ARGS+=	--enable-debug
.endif
