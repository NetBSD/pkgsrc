# $NetBSD: options.mk,v 1.1 2007/08/02 14:47:24 obache Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.scm
PKG_SUPPORTED_OPTIONS=	x11
PKG_SUGGESTED_OPTIONS=	x11

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mx11)
.include "../../x11/libX11/buildlink3.mk"
SCM_MODULES+=	x
COMPILED_INITS+=init_x
CFLAGS+=	-DX11 -I${X11BASE:Q}/include
LIBS+=		-L${X11BASE:Q}/lib -lX11
.endif
