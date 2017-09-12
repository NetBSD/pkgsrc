# $NetBSD: options.mk,v 1.2 2017/09/12 02:32:17 ryoon Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.pinepgp

PKG_SUPPORTED_OPTIONS=	gpg pgp5
PKG_SUGGESTED_OPTIONS=	gpg
PLIST_VARS=		gpg pgp5

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mgpg)
DEPENDS+=	gnupg>=1.2.3:../../security/gnupg
CONFIGURE_ARGS+=	--with-gpg
PLIST.gpg=yes
.else
CONFIGURE_ARGS+=	--without-gpg
.endif

.if !empty(PKG_OPTIONS:Mpgp5)
DEPENDS+=	pgp5>=5.0:../../security/pgp5
CONFIGURE_ARGS+=	--with-pgp5
PLIST.pgp5=yes
.else
CONFIGURE_ARGS+=	--without-pgp5
.endif
