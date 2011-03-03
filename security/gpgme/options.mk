# $NetBSD: options.mk,v 1.1 2011/03/03 11:39:47 adam Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.gpgme
PKG_SUPPORTED_OPTIONS=	gpgsm
PKG_SUGGESTED_OPTIONS=	gpgsm

.include "../../mk/bsd.options.mk"

##
## Option to build with gpgsm. This provides SMIME support
##
.if !empty(PKG_OPTIONS:Mgpgsm)
.  include "../../security/gnupg2/buildlink3.mk"
CONFIGURE_ARGS+=	--with-gpgsm=${BUILDLINK_PREFIX.gnupg2}/bin/gpgsm
CONFIGURE_ARGS+=	--with-gpg=${BUILDLINK_PREFIX.gnupg2}/bin/gpg2
REPLACE_SH+=		tests/gpg/pinentry
.else
DEPENDS+=		gnupg>=1.4.2:../../security/gnupg
CONFIGURE_ARGS+=	--without-gpgconf
CONFIGURE_ARGS+=	--without-gpgsm
.endif
