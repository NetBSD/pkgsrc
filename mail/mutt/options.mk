# $NetBSD: options.mk,v 1.3 2004/09/12 04:33:12 jlam Exp $

# Global and legacy options
.if defined(MUTT_USE_SLANG) && !empty(MUTT_USE_SLANG:M[yY][eE][sS])
PKG_DEFAULT_OPTIONS+=	slang
.endif
.if defined(MUTT_USE_NCURSES) && !empty(MUTT_USE_NCURSES:M[yY][eE][sS])
PKG_DEFAULT_OPTIONS+=	ncurses
.endif
.if defined(MUTT_USE_SSL) && !empty(MUTT_USE_SSL:M[yY][eE][sS])
PKG_DEFAULT_OPTIONS+=	ssl
.endif
.if defined(MUTT_USE_SASL) && !empty(MUTT_USE_SASL:M[yY][eE][sS])
PKG_DEFAULT_OPTIONS+=	sasl1
.endif

PKG_OPTIONS_VAR=	PKG_OPTIONS.mutt
PKG_SUPPORTED_OPTIONS=	slang ncurses ssl sasl1

.if !defined(PKG_OPTIONS.mutt)
PKG_DEFAULT_OPTIONS+=	ssl
.endif

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
### SASLv1
###
.if !empty(PKG_OPTIONS:Msasl1)
.  include "../../security/cyrus-sasl/buildlink3.mk"
CONFIGURE_ARGS+=	--with-sasl=${BUILDLINK_PREFIX.cyrus-sasl}
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
