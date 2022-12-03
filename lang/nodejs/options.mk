# $NetBSD: options.mk,v 1.15 2022/12/03 17:07:13 adam Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.nodejs
PKG_SUPPORTED_OPTIONS=	openssl
PKG_SUGGESTED_OPTIONS=	openssl

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mopenssl)
.include "../../security/openssl/buildlink3.mk"
CONFIGURE_ARGS+=	--shared-openssl
_WRAP_EXTRA_ARGS.CXX+=	${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.openssl}/lib
CWRAPPERS_APPEND.cxx+=	${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.openssl}/lib
.else
CONFIGURE_ARGS+=	--without-ssl
.endif
