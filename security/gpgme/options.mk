# $NetBSD: options.mk,v 1.12 2018/07/04 12:46:29 adam Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.gpgme
PKG_OPTIONS_REQUIRED_GROUPS=	gnupg
PKG_OPTIONS_GROUP.gnupg=	gnupg1 gnupg2
PKG_SUGGESTED_OPTIONS=		gnupg2

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mgnupg2)
DEPENDS+=		gnupg2>=2.2.0:../../security/gnupg2
REPLACE_SH+=		tests/gpg/pinentry
GPG_DEFAULT=		${PREFIX}/bin/gpg2
MAKE_FLAGS+=		GPG=${GPG_DEFAULT}
.else
DEPENDS+=		gnupg>=1.4.2:../../security/gnupg
CONFIGURE_ARGS+=	--disable-gpgsm-test	# XXX: needs gpgsm
.endif
