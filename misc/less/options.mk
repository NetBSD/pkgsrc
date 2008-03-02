# $NetBSD: options.mk,v 1.1 2008/03/02 15:35:33 bjs Exp $

PKG_OPTIONS_VAR=	 	PKG_OPTIONS.less
PKG_SUPPORTED_OPTIONS=	 	pcre

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mpcre)
CONFIGURE_ARGS+= 	--with-regex=pcre
.  include "../../devel/pcre/buildlink3.mk"
.endif
