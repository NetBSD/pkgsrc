# $NetBSD: options.mk,v 1.3 2019/11/04 21:12:58 rillig Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.pinepgp

PKG_SUPPORTED_OPTIONS=	gpg pgp5
PKG_SUGGESTED_OPTIONS=	gpg
PLIST_VARS=		gpg pgp5

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mgpg)
DEPENDS+=		gnupg>=1.2.3:../../security/gnupg
CONFIGURE_ARGS+=	--with-gpg
PLIST.gpg=		yes
.else
CONFIGURE_ARGS+=	--without-gpg
.endif

.if !empty(PKG_OPTIONS:Mpgp5)
DEPENDS+=		pgp5>=5.0:../../security/pgp5
CONFIGURE_ARGS+=	--with-pgp5
PLIST.pgp5=		yes
.else
CONFIGURE_ARGS+=	--without-pgp5
.endif
