# $NetBSD: options.mk,v 1.7 2005/05/31 10:01:38 dillo Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.mutt
PKG_SUPPORTED_OPTIONS=	slang ncurses ssl buffy-size
PKG_SUGGESTED_OPTIONS=	ssl

.include "../../mk/bsd.options.mk"

###
### Slang and ncurses
###
.if !empty(PKG_OPTIONS:Mslang)
.  include "../../devel/libslang/buildlink3.mk"
CONFIGURE_ARGS+=	--with-slang=${BUILDLINK_PREFIX.libslang}
.else
.  if !empty(PKG_OPTIONS:Mncurses)
USE_NCURSES=		yes
.  endif
.  include "../../devel/ncurses/buildlink3.mk"
CONFIGURE_ARGS+=	--with-curses=${BUILDLINK_PREFIX.ncurses}
.endif

###
### SSL
###
.if !empty(PKG_OPTIONS:Mssl)
.  include "../../security/openssl/buildlink3.mk"
CONFIGURE_ARGS+=	--with-ssl=${SSLBASE}
.else
CONFIGURE_ARGS+=	--without-ssl
.endif

###
### configure option --enable-buffy-size
###
.if !empty(PKG_OPTIONS:Mbuffy-size)
CONFIGURE_ARGS+=	--enable-buffy-size
.endif
