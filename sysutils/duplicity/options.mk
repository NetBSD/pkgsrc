# $NetBSD: options.mk,v 1.5 2021/02/11 10:40:35 adam Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.duplicity
PKG_SUPPORTED_OPTIONS=	gnupg2
PKG_SUGGESTED_OPTIONS=	gnupg2

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mgnupg2)
DEPENDS+=	gnupg2-[0-9]*:../../security/gnupg2
GPGPATH=	${PREFIX}/bin/gpg2
.else
DEPENDS+=	gnupg>=1.0.0:../../security/gnupg
GPGPATH=	${PREFIX}/bin/gpg
.endif
