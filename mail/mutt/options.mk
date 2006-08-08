# $NetBSD: options.mk,v 1.10 2006/08/08 16:17:50 tron Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.mutt
PKG_OPTIONS_OPTIONAL_GROUPS=	display
PKG_OPTIONS_GROUP.display=	slang ncurses
PKG_SUPPORTED_OPTIONS=		ssl buffy-size
PKG_SUGGESTED_OPTIONS=		ssl

.include "../../mk/bsd.options.mk"

###
### Slang
###
.if !empty(PKG_OPTIONS:Mslang)
.  include "../../devel/libslang/buildlink3.mk"
CONFIGURE_ARGS+=	--with-slang=${BUILDLINK_PREFIX.libslang}
.endif

###
### ncurses
###
.if !empty(PKG_OPTIONS:Mncurses)
USE_NCURSES=		yes
.  include "../../devel/ncurses/buildlink3.mk"
CONFIGURE_ARGS+=	--with-curses=${BUILDLINK_PREFIX.ncurses}
.endif

###
### SSL
###
.if !empty(PKG_OPTIONS:Mssl)
.  include "../../security/openssl/buildlink3.mk"
CONFIGURE_ARGS+=	--with-ssl=${SSLBASE:Q}
.else
CONFIGURE_ARGS+=	--without-ssl
.endif

###
### configure option --enable-buffy-size
###
.if !empty(PKG_OPTIONS:Mbuffy-size)
CONFIGURE_ARGS+=	--enable-buffy-size
.endif
