# $NetBSD: options.mk,v 1.7 2017/08/29 12:20:25 wiz Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.gpgme
PKG_OPTIONS_REQUIRED_GROUPS=	gnupg
PKG_OPTIONS_GROUP.gnupg=	gnupg1 gnupg2
PKG_SUGGESTED_OPTIONS=		gnupg2

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mgnupg2)
DEPENDS+=		gnupg2-[0-9]*:../../security/gnupg2
REPLACE_SH+=		tests/gpg/pinentry
GPG_DEFAULT=		${LOCALBASE}/bin/gpg2
MAKE_FLAGS+=		GPG=${GPG_DEFAULT}
.else
DEPENDS+=		gnupg>=1.4.2:../../security/gnupg
.endif
