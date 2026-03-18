# $NetBSD: options.mk,v 1.1 2026/03/18 07:00:47 adam Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.gtkwave
PKG_SUPPORTED_OPTIONS=	gtkwave-tcl gconf
PKG_SUGGESTED_OPTIONS=	gconf

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mgtkwave-tcl)
.include "../../lang/tcl/buildlink3.mk"
.include "../../x11/tk/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-tcl
.endif

.if !empty(PKG_OPTIONS:Mgconf)
CONFIGURE_ARGS+=	--with-gconf
.include "../../devel/gconfmm/buildlink3.mk"
.endif
