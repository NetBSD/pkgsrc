# $NetBSD: options.mk,v 1.1 2013/10/03 11:12:43 obache Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.fdm
PKG_SUPPORTED_OPTIONS=	debug pcre
PKG_SUGGESTED_OPTIONS=	pcre

.include "../../mk/bsd.options.mk"

#
# Debug
#
.if !empty(PKG_OPTIONS:Mdebug)
   MAKE_ENV+=	FDEBUG=1
.endif

#
# PCRE support
#
.if !empty(PKG_OPTIONS:Mpcre)
   MAKE_ENV+=	PCRE=1
.  include "../../devel/pcre/buildlink3.mk"
.endif
