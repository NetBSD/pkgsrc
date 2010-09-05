# $NetBSD: options.mk,v 1.4 2010/09/05 20:33:48 adam Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.openvpn
PKG_SUPPORTED_OPTIONS=	pkcs11 pam
PKG_SUGGESTED_OPTIONS=

.include "../../mk/bsd.options.mk"

# include support for certificates on a stick (or card)

.if !empty(PKG_OPTIONS:Mpkcs11)
.include "../../security/pkcs11-helper/buildlink3.mk"
.else
# it would pick it up halfways when installed, and fail building
CONFIGURE_ARGS+= --disable-pkcs11
.endif

PLIST_VARS+=	pam
.if !empty(PKG_OPTIONS:Mpam)
USE_TOOLS+=	gmake
BUILD_DIRS+=	plugin/auth-pam
BUILD_TARGET=	# empty
INSTALL_DIRS=	.
INSTALL_TARGET=	install
INSTALLATION_DIRS+=	lib/openvpn
PLIST.pam=	yes
post-install-pam:
	cd ${WRKSRC}/plugin/auth-pam &&				\
	${INSTALL_LIB} openvpn-auth-pam.so 			\
		       ${DESTDIR}${PREFIX}/lib/openvpn || ${TRUE}
.include "../../mk/pam.buildlink3.mk"
.else
post-install-pam:
.endif
