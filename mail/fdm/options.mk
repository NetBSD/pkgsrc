# $NetBSD: options.mk,v 1.4 2023/03/19 17:50:10 leot Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.fdm
PKG_SUPPORTED_OPTIONS=	debug pcre
PKG_SUGGESTED_OPTIONS=	pcre

.include "../../mk/bsd.options.mk"

#
# Debug
#
.if !empty(PKG_OPTIONS:Mdebug)
CONFIGURE_ARGS+=	--enable-debug
.endif

#
# PCRE support
#
.if !empty(PKG_OPTIONS:Mpcre)
MAKE_ENV+=	PCRE=1
.  include "../../devel/pcre2/buildlink3.mk"
.endif
