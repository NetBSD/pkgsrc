# $NetBSD: options.mk,v 1.11 2010/07/06 07:33:43 obache Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.msmtp

PKG_OPTIONS_OPTIONAL_GROUPS=	ssl
PKG_OPTIONS_GROUP.ssl=	gnutls ssl

PKG_SUPPORTED_OPTIONS=	gnome-keyring gsasl idn inet6
PKG_SUGGESTED_OPTIONS=	ssl

.include "../../mk/bsd.options.mk"

###
### SSL support
###
.if !empty(PKG_OPTIONS:Mssl)
.  include "../../security/openssl/buildlink3.mk"
CONFIGURE_ARGS+=	--with-ssl=openssl
CONFIGURE_ARGS+=	--with-libssl-prefix=${BUILDLINK_PREFIX.openssl}
.elif !empty(PKG_OPTIONS:Mgnutls)
.  include "../../security/gnutls/buildlink3.mk"
CONFIGURE_ARGS+=	--with-ssl=gnutls
CONFIGURE_ARGS+=	--with-libgnutls-prefix=${BUILDLINK_PREFIX.gnutls}
.else
CONFIGURE_ARGS+=	--disable-ssl
.endif

###
### GNUsasl support
###
.if !empty(PKG_OPTIONS:Mgsasl)
.  include "../../security/gsasl/buildlink3.mk"
CONFIGURE_ARGS+=	--with-libgsasl
CONFIGURE_ARGS+=	--with-libgsasl-prefix=${BUILDLINK_PREFIX.gsasl}
.else
CONFIGURE_ARGS+=	--without-libgsasl
.endif

###
### Internationalized Domain Names (IDN) support
###
.if !empty(PKG_OPTIONS:Midn)
.  include "../../devel/libidn/buildlink3.mk"
CONFIGURE_ARGS+=	--with-libidn
CONFIGURE_ARGS+=	--with-libidn-prefix=${BUILDLINK_PREFIX.libidn}
.else
CONFIGURE_ARGS+=	--without-libidn
.endif

###
### GNOME keyring support
###
.if !empty(PKG_OPTIONS:Mgnome-keyring)
.  include "../../security/gnome-keyring/buildlink3.mk"
CONFIGURE_ARGS+=	--with-gnome-keyring
USE_TOOLS+=		pkg-config
.else
CONFIGURE_ARGS+=	--without-gnome-keyring
.endif
