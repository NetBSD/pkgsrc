# $NetBSD: options.mk,v 1.1 2020/11/22 11:33:22 schmonz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.s6-networking
PKG_SUPPORTED_OPTIONS+=	tls
PKG_SUGGESTED_OPTIONS+=	tls

.include "../../mk/bsd.options.mk"

PLIST_VARS=		tls
.if !empty(PKG_OPTIONS:Mtls)
PLIST.tls=		yes
.  include "../../security/bearssl/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-ssl=bearssl
.endif
