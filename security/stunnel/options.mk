# $NetBSD: options.mk,v 1.4 2008/09/19 19:20:57 adrianp Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.stunnel
PKG_SUPPORTED_OPTIONS=	inet6 pthread libwrap
PKG_SUGGESTED_OPTIONS=	libwrap
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

###
### Support libwrap
###
.if !empty(PKG_OPTIONS:Mlibwrap)
CONFIGURE_ARGS+=	--enable-libwrap
.else
CONFIGURE_ARGS+=	--disable-libwrap
.endif
