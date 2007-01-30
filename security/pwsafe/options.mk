# $NetBSD: options.mk,v 1.2 2007/01/30 20:53:24 joerg Exp $

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

BUILDLINK_DEPMETHOD.libXt?=	build

.include "../../x11/libSM/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXmu/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-x
.endif
