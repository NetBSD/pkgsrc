# $NetBSD: options.mk,v 1.14 2026/01/29 10:03:12 wiz Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.gpgme
PKG_OPTIONS_REQUIRED_GROUPS=	gnupg
PKG_OPTIONS_GROUP.gnupg=	gnupg1 gnupg2
PKG_SUGGESTED_OPTIONS=		gnupg2

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mgnupg2)
DEPENDS+=		gnupg2>=2.4.9nb2:../../security/gnupg2
REPLACE_SH+=		tests/gpg/pinentry
GPG_DEFAULT=		${PREFIX}/bin/gpg
MAKE_FLAGS+=		GPG=${GPG_DEFAULT}
.else
DEPENDS+=		gnupg>=1.4.23nb28:../../security/gnupg
GPG_DEFAULT=		${PREFIX}/bin/gpg1
CONFIGURE_ARGS+=	--disable-gpgsm-test	# XXX: needs gpgsm
.endif
