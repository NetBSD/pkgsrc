# $NetBSD: options.mk,v 1.2 2013/05/23 11:22:44 fhajny Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.node
PKG_SUPPORTED_OPTIONS=	openssl dtrace
PKG_SUGGESTED_OPTIONS=	openssl

.if ${OPSYS} == "SunOS" && exists(/usr/sbin/dtrace)
PKG_SUGGESTED_OPTIONS+=	dtrace
.endif

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mdtrace)
CONFIGURE_ARGS+=	--with-dtrace
.else
CONFIGURE_ARGS+=	--without-dtrace
.endif

.if !empty(PKG_OPTIONS:Mopenssl)
.include "../../security/openssl/buildlink3.mk"
CONFIGURE_ARGS+=	--shared-openssl
.else
CONFIGURE_ARGS+=	--without-openssl
.endif

.if empty(PKG_OPTIONS:Msnapshot)
CONFIGURE_ARGS+=	--without-snapshot
.endif
