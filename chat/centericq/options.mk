# $NetBSD: options.mk,v 1.2 2007/04/15 20:16:42 wiz Exp $
#

PKG_OPTIONS_VAR=	PKG_OPTIONS.centericq
PKG_SUPPORTED_OPTIONS=	gpgme
PKG_SUGGESTED_OPTIONS=	gpgme

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mgpgme)
CONFIGURE_ARGS+=	--with-gpgme=${BUILDLINK_PREFIX.gpgme}
.  include "../../security/gpgme/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-gpgme
.endif
