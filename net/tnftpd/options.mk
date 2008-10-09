# $NetBSD: options.mk,v 1.2 2008/10/09 04:14:29 lukem Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.tnftpd
PKG_SUPPORTED_OPTIONS=	inet6 pam

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Minet6)
CONFIGURE_ARGS+=	--enable-ipv6
.else
CONFIGURE_ARGS+=	--disable-ipv6
.endif

.if !empty(PKG_OPTIONS:Mpam)
.include "../../mk/pam.buildlink3.mk"
CONFIGURE_ARGS+=	--with-pam
.endif
