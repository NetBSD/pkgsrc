# $NetBSD: options.mk,v 1.5 2017/04/05 08:58:24 wiz Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.gpgme
PKG_OPTIONS_REQUIRED_GROUPS=	gnupg
PKG_OPTIONS_GROUP.gnupg=	gnupg1 gnupg2 gnupg21
PKG_SUGGESTED_OPTIONS=		gnupg2

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mgnupg21)
DEPENDS+=		gnupg21>=2.1:../../security/gnupg21
REPLACE_SH+=		tests/gpg/pinentry
GPG_DEFAULT=		${LOCALBASE}/bin/gpg2
MAKE_FLAGS+=		GPG=${GPG_DEFAULT}
.elif !empty(PKG_OPTIONS:Mgnupg2)
DEPENDS+=		gnupg2>=2.0<2.1:../../security/gnupg2
REPLACE_SH+=		tests/gpg/pinentry
GPG_DEFAULT=		${LOCALBASE}/bin/gpg2
MAKE_FLAGS+=		GPG=${GPG_DEFAULT}
.else
DEPENDS+=		gnupg>=1.4.2:../../security/gnupg
.endif
