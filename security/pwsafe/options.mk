# $NetBSD: options.mk,v 1.1.1.1 2005/07/31 01:06:02 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.pwsafe
PKG_SUPPORTED_OPTIONS=	readline x11

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mreadline)
CONFIGURE_ARGS+=	--with-readline
.  if ${OPSYS} == "NetBSD"
# The NetBSD readline implementation isn't GNU compatible
USE_GNU_READLINE=	yes
.  endif
.  include "../../devel/readline/buildlink3.mk"
.  include "../../devel/ncurses/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-readline
.endif

.if !empty(PKG_OPTIONS:Mx11)
CONFIGURE_ARGS+=	--with-x
.include "../../mk/x11.buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-x
.endif
