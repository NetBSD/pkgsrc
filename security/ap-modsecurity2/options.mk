# $NetBSD: options.mk,v 1.3 2008/10/12 12:50:17 adrianp Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.ap-modsecurity2

PKG_SUPPORTED_OPTIONS=	curl

.include "../../mk/bsd.options.mk"

###
### Bring in support for libxml2
###
.if !empty(PKG_OPTIONS:Mxml)
.  include "../../textproc/libxml2/buildlink3.mk"
CONFIGURE_ARGS+=	--with-libxml
MESSAGE_SRC+=		${WRKDIR}/.MESSAGE_SRC.xml
.else
CONFIGURE_ARGS+=	--without-libxml
.endif

###
### Bring in support for curl
###
.if !empty(PKG_OPTIONS:Mcurl)
.  include "../../www/curl/buildlink3.mk"
CONFIGURE_ARGS+=	--with-curl=${PREFIX}/bin/curl
.else
CONFIGURE_ARGS+=	--without-curl
.endif
