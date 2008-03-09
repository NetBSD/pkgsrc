# $NetBSD: options.mk,v 1.1 2008/03/09 20:56:57 bjs Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.rsync
PKG_SUPPORTED_OPTIONS=	debug inet6

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Minet6)
CONFIGURE_ARGS+=	--enable-ipv6
.else
CONFIGURE_ARGS+=	--disable-ipv6
.endif

.if !empty(PKG_OPTIONS:Mdebug)
CONFIGURE_ARGS+=	--enable-debug
MAKE_ENV+= 		STRIP_RSYNC=${STRIP}
.else
CONFIGURE_ARGS+=	--disable-debug
MAKE_ENV+= 	 	STRIP_RSYNC=${TRUE}
.endif
