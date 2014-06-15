# $NetBSD: options.mk,v 1.3 2014/06/15 19:15:51 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.mupdf
PKG_SUPPORTED_OPTIONS=	curl

.include "../../mk/bsd.options.mk"

#
# curl support
#
.if !empty(PKG_OPTIONS:Mcurl)
.include "../../www/curl/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.endif
