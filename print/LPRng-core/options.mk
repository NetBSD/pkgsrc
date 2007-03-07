# $NetBSD: options.mk,v 1.3 2007/03/07 11:04:40 rillig Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.LPRng-core
PKG_SUPPORTED_OPTIONS=	kerberos lprng-priv-ports lprng-suid
PKG_SUGGESTED_OPTIONS=	lprng-suid

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mlprng-priv-ports)
CONFIGURE_ARGS+=	--enable-priv_ports
.endif
.if empty(PKG_OPTIONS:Mlprng-suid)
CONFIGURE_ARGS+=	--disable-setuid
.endif
.if !empty(PKG_OPTIONS:Mkerberos)
CONFIGURE_ARGS+=	--enable-kerberos
KRB5_ACCEPTED=		mit-krb5
.  include "../../mk/krb5.buildlink3.mk"
.endif
