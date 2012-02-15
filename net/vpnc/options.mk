# $NetBSD: options.mk,v 1.3 2012/02/15 13:02:31 obache Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.openvpnc
PKG_SUPPORTED_OPTIONS=	openssl		# off by default
PKG_SUGGESTED_OPTIONS=

.include "../../mk/bsd.prefs.mk"
.include "../../mk/bsd.options.mk"
.if !empty(PKG_OPTIONS:Mopenssl)
.include "../../security/openssl/buildlink3.mk"
SUBST_CLASSES+=		openssl
SUBST_MESSAGE.openssl=	adding openssl option
SUBST_STAGE.openssl=	post-patch
SUBST_FILES.openssl=	Makefile
SUBST_SED.openssl=	-e 's/^.OPENSSL_GPL_VIOLATION/OPENSSL_GPL_VIOLATION/'
SUBST_SED.openssl+=	-e 's/^.OPENSSLLIBS/OPENSSLLIBS/'
.endif
