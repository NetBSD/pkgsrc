# $NetBSD: options.mk,v 1.1 2017/09/09 11:43:08 ryoon Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.pinepgp

PKG_SUPPORTED_OPTIONS=	gpg pgp5
PKG_SUGGESTED_OPTIONS=	gpg
PLIST_VARS=		gpg pgp5

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mgpg)
DEPENDS+=	gnupg>=1.2.3:../../security/gnupg
.endif

.if !empty(PKG_OPTIONS:Mpgp5)
DEPENDS+=	pgp5>=5.0:../../security/pgp5
.endif
