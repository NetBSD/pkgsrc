# $NetBSD: options.mk,v 1.2 2014/04/21 16:14:40 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.mupdf
PKG_SUPPORTED_OPTIONS=	curl

.include "../../mk/bsd.options.mk"

#
# curl support
#
.if !empty(PKG_OPTIONS:Mcurl)
MAKE_FLAGS+=	HAVE_CURL=yes
.include "../../www/curl/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.endif
