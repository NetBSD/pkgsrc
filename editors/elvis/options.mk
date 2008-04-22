# $NetBSD: options.mk,v 1.1 2008/04/22 16:23:57 jlam Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.elvis
PKG_SUPPORTED_OPTIONS=		x11

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mx11)
BUILDLINK_DEPMETHOD.libXt?=	build
.  include "../../x11/libXft/buildlink3.mk"
.  include "../../x11/libXpm/buildlink3.mk"
.  include "../../x11/libXt/buildlink3.mk"
CONFIGURE_ARGS+=		--with-x
CONFIGURE_ARGS+=		--with-xft
CONFIGURE_ARGS+=		--x-includes=${X11BASE:Q}/include
CONFIGURE_ARGS+=		--x-libraries=${X11BASE:Q}/lib
.else
CONFIGURE_ARGS+=		--without-x
.endif
