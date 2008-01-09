# $NetBSD: options.mk,v 1.1 2008/01/09 13:40:38 heinz Exp $
#
PKG_OPTIONS_VAR=	PKG_OPTIONS.rlwrap
PKG_SUPPORTED_OPTIONS=	debug
PKG_SUGGESTED_OPTIONS=	# empty

.include "../../mk/bsd.prefs.mk"
.include "../../mk/bsd.options.mk"

###
### debug option
###

.if !empty(PKG_OPTIONS:Mdebug)
CONFIGURE_ARGS+=	--enable-debug
.endif
