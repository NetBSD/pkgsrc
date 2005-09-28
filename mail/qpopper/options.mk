# $NetBSD: options.mk,v 1.9 2005/09/28 21:55:32 rillig Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.qpopper
PKG_SUPPORTED_OPTIONS=	drac inet6 kerberos pam qpopper-servermode ssl
PKG_SUGGESTED_OPTIONS=	ssl
PKG_OPTIONS_LEGACY_VARS+=	QPOPPER_SERVERMODE:qpopper-servermode
PKG_OPTIONS_LEGACY_VARS+=	QPOPPER_USE_DRAC:drac

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mssl)
.  include "../../security/openssl/buildlink3.mk"
CONFIGURE_ARGS+=	--with-openssl=${SSLBASE}
.else
CONFIGURE_ARGS+=	--without-ssl
.endif

.if !empty(PKG_OPTIONS:Minet6)
CONFIGURE_ENV+=		O_DEFS="${O_DEFS}" CFLAGS="-DINET6"
.else
CONFIGURE_ARGS+=	--disable-ipv6
.endif

# Please note this is currently experimental for platforms that support it
.if !empty(PKG_OPTIONS:Mpam)
.  include "../../mk/pam.buildlink3.mk"
CONFIGURE_ARGS+=        --with-pam
.else
CONFIGURE_ARGS+=	--without-pam
.endif

.if !empty(PKG_OPTIONS:Mkerberos)
PKG_USE_KERBEROS=	yes
CONFIGURE_ARGS+=	--enable-kerberos
.endif

.if !empty(PKG_OPTIONS:Mqpopper-servermode)
CONFIGURE_ARGS+=	--enable-servermode
.endif

.if !empty(PKG_OPTIONS:Mdrac)
.include "../../mail/drac/buildlink3.mk"
CONFIGURE_ARGS+=	--with-drac=${BUILDLINK_PREFIX.drac}
.endif
