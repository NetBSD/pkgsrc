# $NetBSD: options.mk,v 1.4 2011/03/19 13:31:52 obache Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.ap-modsecurity2

PKG_SUPPORTED_OPTIONS=	curl

.include "../../mk/bsd.options.mk"

###
### Bring in support for curl
###
.if !empty(PKG_OPTIONS:Mcurl)
.  include "../../www/curl/buildlink3.mk"
CONFIGURE_ARGS+=	--with-curl=${BUILDLINK_PREFIX.curl}
.else
CONFIGURE_ARGS+=	--without-curl
.endif
