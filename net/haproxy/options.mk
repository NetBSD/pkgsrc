# $NetBSD: options.mk,v 1.1.2.2 2014/09/13 18:13:24 tron Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.haproxy
PKG_SUPPORTED_OPTIONS=	pcre ssl
PKG_SUGGESTED_OPTIONS=	pcre

.include "../../mk/bsd.options.mk"

###
### Use libpcre rather than libc for header processing regexp
###
.if !empty(PKG_OPTIONS:Mpcre)
.  include "../../devel/pcre/buildlink3.mk"
BUILD_MAKE_FLAGS+=	USE_PCRE=1
.endif

###
### Support OpenSSL for termination.
###
.if !empty(PKG_OPTIONS:Mssl)
.  include "../../security/openssl/buildlink3.mk"
BUILD_MAKE_FLAGS+=	USE_OPENSSL=1
.endif
