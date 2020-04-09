# $NetBSD: options.mk,v 1.8.2.1 2020/04/09 10:57:11 bsiegert Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.haproxy
PKG_SUPPORTED_OPTIONS=		lua prometheus ssl
PKG_OPTIONS_OPTIONAL_GROUPS=	regex
PKG_OPTIONS_GROUP.regex=	pcre pcre2 pcre2-jit
PKG_SUGGESTED_OPTIONS=		pcre ssl

.include "../../mk/bsd.options.mk"

###
### Use libpcre rather than libc for header processing regexp
###
.if !empty(PKG_OPTIONS:Mpcre)
.  include "../../devel/pcre/buildlink3.mk"
BUILD_MAKE_FLAGS+=	USE_PCRE=1
.endif

.if !empty(PKG_OPTIONS:Mpcre2)
.  include "../../devel/pcre2/buildlink3.mk"
BUILD_MAKE_FLAGS+=	USE_PCRE2=1
.endif

.if !empty(PKG_OPTIONS:Mpcre2-jit)
.  include "../../devel/pcre2/buildlink3.mk"
BUILD_MAKE_FLAGS+=	USE_PCRE2_JIT=1
.endif

###
### Use LUA
###
.if !empty(PKG_OPTIONS:Mlua)
LUA_VERSIONS_ACCEPTED=	53
.  include "../../lang/lua/luaversion.mk"
BUILD_MAKE_FLAGS+=	USE_LUA=1
BUILD_MAKE_FLAGS+=	LUA_LIB_NAME=lua5.3
.  include "../../lang/lua/buildlink3.mk"
.endif

###
### Use Prometheus
###
.if !empty(PKG_OPTIONS:Mprometheus)
BUILD_MAKE_FLAGS+=	EXTRA_OBJS="contrib/prometheus-exporter/service-prometheus.o"
.endif

###
### Support OpenSSL for termination.
###
.if !empty(PKG_OPTIONS:Mssl)
.  include "../../security/openssl/buildlink3.mk"
BUILD_MAKE_FLAGS+=	USE_OPENSSL=1
.endif
