# $NetBSD: options.mk,v 1.4 2014/07/25 15:29:38 jperkin Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.ssmtp
PKG_SUPPORTED_OPTIONS=	inet6 ssl
PKG_SUGGESTED_OPTIONS=	inet6 ssl

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Minet6)
CONFIGURE_ARGS+=	--enable-inet6
.endif

.if !empty(PKG_OPTIONS:Mssl)
CONFIGURE_ARGS+=	--enable-ssl
CFLAGS+=		${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.openssl}/lib
.include "../../security/openssl/buildlink3.mk"
.endif
