# $NetBSD: options.mk,v 1.1 2005/11/24 19:04:34 wiz Exp $

.include "../../mk/bsd.prefs.mk"

# Kerberos is explicitly not enabled on NetBSD 1.x due to interoperability
# issues with later versions of OpenSSL (e.g. 0.9.7)
.if empty(MACHINE_PLATFORM:MNetBSD-1.*)
PKG_SUPPORTED_OPTIONS+=		kerberos
.endif

PKG_OPTIONS_VAR=	PKG_OPTIONS.imap-uw
PKG_SUPPORTED_OPTIONS+=	inet6 ssl imapuw-cleartextpwd imapuw-whoson
PKG_SUGGESTED_OPTIONS+=	ssl imapuw-cleartextpwd
# remove after 2005q4
PKG_OPTIONS_LEGACY_VARS+=	IMAP_UW_NO_SSL:-ssl
PKG_OPTIONS_LEGACY_VARS+=	IMAP_UW_USE_WHOSON:imapuw-whoson
PKG_OPTIONS_LEGACY_VARS+=	IMAP_UW_NO_CLEARTEXT:-imapuw-cleartextpwd

.include "../../mk/bsd.options.mk"

.if empty(PKG_OPTIONS:Minet6)
MAKE_ENV+=	IP=4
.else
MAKE_ENV+=	IP=6
.endif

.if !empty(PKG_OPTIONS:Mkerberos)
PKG_USE_KERBEROS=	yes

BUILD_TARGET+=	EXTRAAUTHENTICATORS="gss"
.endif

.if !empty(PKG_OPTIONS:Mssl)
.include "../../security/openssl/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mimapuw-whoson)
LDFLAGS+=	-lwhoson
CFLAGS+=	-DUSE_WHOSON
.include "../../net/whoson/buildlink3.mk"
.endif

.if empty(PKG_OPTIONS:Mimapuw-cleartextpwd)
BUILD_TARGET+=	SSLTYPE="nopwd"
.elif !empty(PKG_OPTIONS:Mssl)
BUILD_TARGET+=	SPECIALAUTHENTICATORS="ssl"
BUILD_TARGET+=	SSLTYPE="unix"
.endif
