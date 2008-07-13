PKG_OPTIONS_VAR=	PKG_OPTIONS.openvpnc
PKG_SUPPORTED_OPTIONS=	openssl		# off by default
PKG_SUGGESTED_OPTIONS=

.include "../../mk/bsd.prefs.mk"
.include "../../mk/bsd.options.mk"
.if !empty(PKG_OPTIONS:Mopenssl)
SUBST_CLASSES+=		openssl
SUBST_MESSAGE.openssl=	adding openssl option
SUBST_STAGE.openssl=	post-patch
SUBST_FILES.openssl=	Makefile
SUBST_SED.openssl=	-e 's/^.OPENSSL_GPL_VIOLATION/OPENSSL_GPL_VIOLATION/'
SUBST_SED.openssl+=	-e 's/^.OPENSSLLIBS/OPENSSLLIBS/'
.endif
