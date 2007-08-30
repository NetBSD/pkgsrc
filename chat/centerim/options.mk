# $NetBSD: options.mk,v 1.1.1.1 2007/08/30 00:47:01 jnemeth Exp $
#

PKG_OPTIONS_VAR=	PKG_OPTIONS.centerim
PKG_SUPPORTED_OPTIONS=	gpgme
PKG_SUGGESTED_OPTIONS=	gpgme

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mgpgme)
#CONFIGURE_ARGS+=	--with-gpgme=${BUILDLINK_PREFIX.gpgme}
#CONFIGURE_ARGS+=	--with-gpgme=${BUILDLINK_PREFIX.gpgme:Q}/bin/gpgme-config
.  include "../../security/gpgme/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-gpgme
.endif
