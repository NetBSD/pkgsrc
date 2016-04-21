# $NetBSD: options.mk,v 1.3 2016/04/21 21:32:03 prlw1 Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.libsoup
PKG_SUPPORTED_OPTIONS=	gssapi
PKG_SUGGESTED_OPTIONS=

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mgssapi)
.  include "../../mk/krb5.buildlink3.mk"
CONFIGURE_ARGS+=	--with-gssapi
CONFIGURE_ARGS+=	--with-krb5-config=${SH_KRB5_CONFIG}
.else
CONFIGURE_ARGS+=	--without-gssapi
.endif
