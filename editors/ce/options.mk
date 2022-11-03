# $NetBSD: options.mk,v 1.1 2022/11/03 14:34:02 schmonz Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.ce
PKG_SUPPORTED_OPTIONS+=		x11

.include "../../mk/bsd.options.mk"

PLIST_VARS+=			x11
.if !empty(PKG_OPTIONS:Mx11)
PLIST.x11=			yes
BUILDLINK_DEPMETHOD.libXt?=	build
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.endif
