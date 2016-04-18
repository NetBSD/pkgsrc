# $NetBSD: options.mk,v 1.1 2016/04/18 17:49:20 bsiegert Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.duplicity
PKG_SUPPORTED_OPTIONS=	gnupg2

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mgnupg2)
DEPENDS+=	gnupg2-[0-9]*:../../security/gnupg2
EVAL_PREFIX=	GNUPG2_PREFIX=gnupg2
GPGPATH=	${GNUPG2_PREFIX}/bin/gpg2
.else
DEPENDS+=	gnupg>=1.0.0:../../security/gnupg
EVAL_PREFIX=	GNUPG_PREFIX=gnupg
GPGPATH=	${GNUPG_PREFIX}/bin/gpg
.endif
