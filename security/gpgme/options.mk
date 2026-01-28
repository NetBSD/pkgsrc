# $NetBSD: options.mk,v 1.13 2026/01/28 10:50:49 wiz Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.gpgme
PKG_OPTIONS_REQUIRED_GROUPS=	gnupg
PKG_OPTIONS_GROUP.gnupg=	gnupg1 gnupg2
PKG_SUGGESTED_OPTIONS=		gnupg2

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mgnupg2)
DEPENDS+=		gnupg2>=2.5:../../security/gnupg2
REPLACE_SH+=		tests/gpg/pinentry
MAKE_FLAGS+=		GPG=${GPG_DEFAULT}
.else
DEPENDS+=		gnupg>=1.4.23nb28:../../security/gnupg
GPG_DEFAULT=		${PREFIX}/bin/gpg1
CONFIGURE_ARGS+=	--disable-gpgsm-test	# XXX: needs gpgsm
.endif
