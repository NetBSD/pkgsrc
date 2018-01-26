# $NetBSD: options.mk,v 1.4 2018/01/26 14:53:05 triaxx Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.duplicity
PKG_SUPPORTED_OPTIONS=	gnupg2
PKG_SUGGESTED_OPTIONS=

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mgnupg2)
DEPENDS+=	gnupg2-[0-9]*:../../security/gnupg2
GPGPATH=	${PREFIX}/bin/gpg2
.else
DEPENDS+=	gnupg>=1.0.0:../../security/gnupg
GPGPATH=	${PREFIX}/bin/gpg
.endif
