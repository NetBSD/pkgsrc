# $NetBSD: options.mk,v 1.6 2017/11/22 08:42:24 leot Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.nmh
PKG_SUPPORTED_OPTIONS=		nmh-backup-hash oauth sasl tls

.include "../../mk/bsd.options.mk"

###
### Prepend a "#" instead of a "," to the name of a message that is
### "removed" by rmm.
###
.if !empty(PKG_OPTIONS:Mnmh-backup-hash)
CONFIGURE_ARGS+=	--with-hash-backup
.else
CONFIGURE_ARGS+=	--without-hash-backup
.endif

.if !empty(PKG_OPTIONS:Moauth)
CONFIGURE_ARGS+=	--with-oauth
.include "../../www/curl/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-oauth
.endif

.if !empty(PKG_OPTIONS:Msasl)
CONFIGURE_ARGS+=	--with-cyrus-sasl
.include "../../security/cyrus-sasl/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-cyrus-sasl
.endif

.if !empty(PKG_OPTIONS:Mtls)
CONFIGURE_ARGS+=	--with-tls
.include "../../security/openssl/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-tls
.endif
