# $NetBSD: options.mk,v 1.5 2016/03/09 03:26:14 tnn Exp $

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
CFLAGS+=		-L${BUILDLINK_PREFIX.openssl}/lib
.include "../../security/openssl/buildlink3.mk"
.endif
