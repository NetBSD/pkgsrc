# $NetBSD: options.mk,v 1.6 2013/10/14 06:51:02 adam Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.cvs
PKG_SUPPORTED_OPTIONS=	kerberos

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mkerberos)
.  include "../../mk/krb5.buildlink3.mk"
CONFIGURE_ARGS+=	--enable-encryption
CONFIGURE_ARGS+=	--enable-pam
CONFIGURE_ARGS+=	--with-gssapi=${KRB5BASE}
CONFIGURE_ARGS+=	--with-krb4=${KRB5BASE}
.else
CONFIGURE_ARGS+=	--without-gssapi
.endif
