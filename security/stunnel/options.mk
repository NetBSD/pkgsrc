# $NetBSD: options.mk,v 1.3 2007/08/11 14:41:36 schmonz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.stunnel
PKG_SUPPORTED_OPTIONS=	inet6 pthread
.if defined(PTHREAD_TYPE) && ${PTHREAD_TYPE} != "none"
PKG_SUGGESTED_OPTIONS+=	pthread
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
.if !empty(PKG_OPTIONS:Mpthread)
CONFIGURE_ARGS+=	--with-threads=pthread
CONFIGURE_ENV+=		CPPFLAGS="${CPPFLAGS} ${PTHREAD_CFLAGS}" \
			LDFLAGS="${LDFLAGS} ${PTHREAD_LIBS}"
.else
CONFIGURE_ARGS+=	--with-threads=fork
.endif
