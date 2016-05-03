# $NetBSD: options.mk,v 1.4 2016/05/03 11:37:39 prlw1 Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.libsoup
PKG_SUPPORTED_OPTIONS=	gssapi
PKG_SUGGESTED_OPTIONS=

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mgssapi)
.  include "../../mk/krb5.buildlink3.mk"
CONFIGURE_ARGS+=	--with-gssapi
CONFIGURE_ARGS+=	--with-krb5-config=${KRB5_CONFIG}
.else
CONFIGURE_ARGS+=	--without-gssapi
.endif
