# $NetBSD: options.mk,v 1.2 2004/08/05 03:30:16 jlam Exp $

# Global and legacy options
.if defined(MUTT_USE_SLANG) || defined(MUTT_USE_NCURSES) || \
    defined(MUTT_USE_SSL) || defined(MUTT_USE_SASL)
.  if !defined(PKG_OPTIONS.mutt)
.    if defined(MUTT_USE_SLANG) && !empty(MUTT_USE_SLANG:M[yY][eE][sS])
PKG_OPTIONS.mutt+=	slang
.    endif
.    if defined(MUTT_USE_NCURSES) && !empty(MUTT_USE_NCURSES:M[yY][eE][sS])
PKG_OPTIONS.mutt+=	ncurses
.    endif
.    if defined(MUTT_USE_SSL) && !empty(MUTT_USE_SSL:M[yY][eE][sS])
PKG_OPTIONS.mutt+=	ssl
.    endif
.    if defined(MUTT_USE_SASL) && !empty(MUTT_USE_SASL:M[yY][eE][sS])
PKG_OPTIONS.mutt+=	sasl
.    endif
.  endif
.endif

PKG_OPTIONS_VAR=	PKG_OPTIONS.mutt
PKG_OPTIONS.mutt?=	ssl
PKG_SUPPORTED_OPTIONS=	slang ncurses ssl sasl
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
### SASLv2
###
.if !empty(PKG_OPTIONS:Msasl)
.  include "../../security/cyrus-sasl2/buildlink3.mk"
CONFIGURE_ARGS+=	--with-sasl2=${BUILDLINK_PREFIX.cyrus-sasl}
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
