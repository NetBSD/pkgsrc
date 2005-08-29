# $NetBSD: options.mk,v 1.2 2005/08/29 11:35:51 xtraeme Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.gaim
PKG_SUPPORTED_OPTIONS+=		gnutls
PKG_SUGGESTED_OPTIONS+=		gtk-spell

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mgnutls)
CONFIGURE_ARGS+=	--disable-nss
CONFIGURE_ARGS+= --with-gnutls-includes=${BUILDLINK_PREFIX.gnutls}/include
CONFIGURE_ARGS+= --with-gnutls-libs=${BUILDLINK_PREFIX.gnutls}/lib

.  include "../../security/gnutls/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-gnutls
CONFIGURE_ARGS+=	--with-nspr-includes=${BUILDLINK_PREFIX.nspr}/include/nspr
CONFIGURE_ARGS+=	--with-nspr-libs=${BUILDLINK_PREFIX.nspr}/lib/nspr
CONFIGURE_ARGS+=	--with-nss-includes=${BUILDLINK_PREFIX.nss}/include/nss/nss
CONFIGURE_ARGS+=	--with-nss-libs=${BUILDLINK_PREFIX.nss}/lib/nss

.  include "../../devel/nss/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mgtkspell)
.  include "../../textproc/gtkspell/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-gtkspell
.endif
