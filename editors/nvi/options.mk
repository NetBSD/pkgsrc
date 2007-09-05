# $NetBSD: options.mk,v 1.1 2007/09/05 23:05:13 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.nvi
PKG_SUPPORTED_OPTIONS=	ncursesw

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mncursesw)
.  include "../../devel/ncursesw/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-widechar
#CONFIGURE_ARGS+=	--with-curses=${BUILDLINK_PREFIX.ncursesw}
.else
.  include "../../mk/curses.buildlink3.mk"
.endif
