# $NetBSD: options.mk,v 1.9 2017/12/21 13:30:40 ryoon Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.gpgme
PKG_OPTIONS_REQUIRED_GROUPS=	gnupg
PKG_OPTIONS_GROUP.gnupg=	gnupg1 gnupg2
PKG_SUGGESTED_OPTIONS=		gnupg2

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mgnupg2)
DEPENDS+=		gnupg2>=2.2.0:../../security/gnupg2
REPLACE_SH+=		tests/gpg/pinentry
GPG_DEFAULT=		${LOCALBASE}/bin/gpg2
MAKE_FLAGS+=		GPG=${GPG_DEFAULT}
.else
DEPENDS+=		gnupg>=1.4.2:../../security/gnupg
.endif
