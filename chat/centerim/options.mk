# $NetBSD: options.mk,v 1.2 2008/08/02 05:39:20 obache Exp $
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
CONFIGURE_ARGS+=	--without-gpgme-prefix
CONFIGURE_ENV+=		ac_cv_path_GPGME_CONFIG=
.endif
