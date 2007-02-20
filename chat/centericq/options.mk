# $NetBSD: options.mk,v 1.1 2007/02/20 17:38:52 sborrill Exp $
#

PKG_OPTIONS_VAR=	PKG_OPTIONS.centericq
PKG_SUPPORTED_OPTIONS=	gpgme
PKG_SUGGESTED_OPTIONS=	gpgme

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mgpgme)
CONFIGURE_ARGS+=	--with-gpgme=${BUILDLINK_PREFIX.gpgme}/bin/gpgme-config
.  include "../../security/gpgme/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-gpgme
.endif
