# $NetBSD: options.mk,v 1.5 2011/04/28 07:27:24 adam Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.openvpn
PKG_SUPPORTED_OPTIONS=	pkcs11 pam
PKG_SUGGESTED_OPTIONS=

.include "../../mk/bsd.options.mk"

# include support for certificates on a stick (or card)
.if !empty(PKG_OPTIONS:Mpkcs11)
.include "../../security/pkcs11-helper/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-pkcs11
.endif

PLIST_VARS+=		pam
.if !empty(PKG_OPTIONS:Mpam)
PLIST.pam=		yes
USE_TOOLS+=		gmake

BUILD_DIRS+=		plugin/auth-pam
BUILD_TARGET=		# empty
INSTALL_DIRS=		.
INSTALL_TARGET=		install
INSTALLATION_DIRS+=	lib/openvpn
post-install-pam:
	${INSTALL_LIB} ${WRKSRC}/plugin/auth-pam/openvpn-auth-pam.so \
		${DESTDIR}${PREFIX}/lib/openvpn || ${TRUE}
.include "../../mk/pam.buildlink3.mk"
.else
post-install-pam:
.endif
