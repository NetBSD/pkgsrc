# $NetBSD: options.mk,v 1.6 2013/02/10 05:55:07 manu Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.openvpn
PKG_SUPPORTED_OPTIONS=	pkcs11 pam
PKG_SUGGESTED_OPTIONS=

.include "../../mk/bsd.options.mk"

# include support for certificates on a stick (or card)
.if !empty(PKG_OPTIONS:Mpkcs11)
.include "../../security/pkcs11-helper/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-pkcs11
.endif

PLIST_VARS+=		pam
.if !empty(PKG_OPTIONS:Mpam)
PLIST.pam=		yes
USE_TOOLS+=		gmake

BUILD_DIRS+=		src/plugins/auth-pam
BUILD_TARGET=		# empty
INSTALL_DIRS=		.
INSTALL_TARGET=		install
.include "../../mk/pam.buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-plugin-auth-pam
.endif
