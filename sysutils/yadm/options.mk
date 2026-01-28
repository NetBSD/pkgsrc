# $NetBSD: options.mk,v 1.2 2026/01/28 10:54:37 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.yadm
PKG_SUPPORTED_OPTIONS=	openssl
PKG_SUGGESTED_OPTIONS=	gnupg2

PKG_OPTIONS_OPTIONAL_GROUPS=	gpg
PKG_OPTIONS_GROUP.gpg=		gnupg1 gnupg2

.include "../../mk/bsd.options.mk"

###
### openssl support
###
.if !empty(PKG_OPTIONS:Mopenssl)
USE_TOOLS+=	openssl:run
YADM_PROGS+=	OPENSSL_PROGRAM="${TOOLS_PATH.openssl}"
.else
YADM_PROGS+=	OPENSSL_PROGRAM="/nonexistent"
.endif

###
### gnupg1 or gnupg2 support
###
.if !empty(PKG_OPTIONS:Mgnupg1)
DEPENDS+=	gnupg>=1.4.23nb28:../../security/gnupg
YADM_PROGS+=	GPG_PROGRAM="${PREFIX}/bin/gpg1"

.elif !empty(PKG_OPTIONS:Mgnupg2)
DEPENDS+=	gnupg2>=2.5:../../security/gnupg2
YADM_PROGS+=	GPG_PROGRAM="${PREFIX}/bin/gpg"

.else
YADM_PROGS+=	GPG_PROGRAM="/nonexistent"
.endif
