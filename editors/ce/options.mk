# $NetBSD: options.mk,v 1.2 2022/12/07 15:41:48 wiz Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.ce
PKG_SUPPORTED_OPTIONS+=		x11

.include "../../mk/bsd.options.mk"

PLIST_VARS+=			x11
.if !empty(PKG_OPTIONS:Mx11)
PLIST.x11=			yes
BUILDLINK_DEPMETHOD.libXt?=	build
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--with-x=no
.endif
