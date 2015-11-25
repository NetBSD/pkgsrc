# $NetBSD: options.mk,v 1.4 2015/11/25 12:58:02 jperkin Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.gpgme
PKG_OPTIONS_REQUIRED_GROUPS=	gnupg
PKG_OPTIONS_GROUP.gnupg=	gnupg1 gnupg2 gnupg21
PKG_SUGGESTED_OPTIONS=		gnupg2

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mgnupg21)
DEPENDS+=		gnupg21>=2.1:../../security/gnupg21
CONFIGURE_ARGS+=	--with-gpgsm=${LOCALBASE}/bin/gpgsm
CONFIGURE_ARGS+=	--with-gpg=${LOCALBASE}/bin/gpg2
REPLACE_SH+=		tests/gpg/pinentry
.elif !empty(PKG_OPTIONS:Mgnupg2)
DEPENDS+=		gnupg2>=2.0<2.1:../../security/gnupg2
CONFIGURE_ARGS+=	--with-gpgsm=${LOCALBASE}/bin/gpgsm
CONFIGURE_ARGS+=	--with-gpg=${LOCALBASE}/bin/gpg2
REPLACE_SH+=		tests/gpg/pinentry
.else
DEPENDS+=		gnupg>=1.4.2:../../security/gnupg
CONFIGURE_ARGS+=	--without-gpgconf
CONFIGURE_ARGS+=	--without-gpgsm
.endif
