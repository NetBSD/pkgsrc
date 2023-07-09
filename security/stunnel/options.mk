# $NetBSD: options.mk,v 1.9 2023/07/09 02:00:52 taca Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.stunnel
PKG_SUPPORTED_OPTIONS=	inet6 threads tcpwrappers
PKG_SUGGESTED_OPTIONS=	inet6 tcpwrappers
CHECK_BUILTIN.pthread:=		yes
.include "../../mk/pthread.builtin.mk"
CHECK_BUILTIN.pthread:=		no

.if "${BUILTIN_LIB_FOUND.pthread:U:tl}" == "yes"
PKG_SUGGESTED_OPTIONS+=	threads
.endif

.include "../../mk/bsd.options.mk"

###
### Support IPv6
###
.if !empty(PKG_OPTIONS:Minet6)
CONFIGURE_ARGS+=	--enable-ipv6
.else
CONFIGURE_ARGS+=	--disable-ipv6
.endif

###
### Support pthreads
###
.if !empty(PKG_OPTIONS:Mthreads)
PTHREAD_AUTO_VARS=	yes
.include "../../mk/pthread.buildlink3.mk"
CONFIGURE_ARGS+=	--with-threads=pthread
.else
CONFIGURE_ARGS+=	--with-threads=fork
.endif

###
### Support tcp_wrappers
###
.if !empty(PKG_OPTIONS:Mtcpwrappers)
.include "../../security/tcp_wrappers/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-libwrap
.endif
