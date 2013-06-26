# $NetBSD: options.mk,v 1.3 2013/06/26 11:51:50 jperkin Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.node
PKG_SUPPORTED_OPTIONS=	openssl dtrace
PKG_SUGGESTED_OPTIONS=	openssl

.if (${OPSYS} == "SunOS" || ${OPSYS} == "Darwin") \
    && exists(/usr/sbin/dtrace)
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
