# $NetBSD: options.mk,v 1.2 2015/09/24 23:33:08 ryoon Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.gpgme
PKG_SUPPORTED_OPTIONS=	gpgsm
PKG_SUGGESTED_OPTIONS=	gpgsm

.include "../../mk/bsd.options.mk"

##
## Option to build with gpgsm. This provides SMIME support
##
.if !empty(PKG_OPTIONS:Mgpgsm)
DEPENDS+=		gnupg2>=2.0<2.1:../../security/gnupg2
FIND_PREFIX:=	GPG2DIR=gnupg2
.include "../../mk/find-prefix.mk"
CONFIGURE_ARGS+=	--with-gpgsm=${GPG2DIR}/bin/gpgsm
CONFIGURE_ARGS+=	--with-gpg=${GPG2DIR}/bin/gpg2
REPLACE_SH+=		tests/gpg/pinentry
.else
DEPENDS+=		gnupg>=1.4.2:../../security/gnupg
CONFIGURE_ARGS+=	--without-gpgconf
CONFIGURE_ARGS+=	--without-gpgsm
.endif
