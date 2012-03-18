# $NetBSD: options.mk,v 1.2 2012/03/18 12:41:53 shattered Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.mtools
PKG_SUPPORTED_OPTIONS=		floppyd
PKG_OPTIONS_LEGACY_VARS+=	MTOOLS_ENABLE_FLOPPYD:floppyd

.include "../../mk/bsd.options.mk"

PLIST_VARS+=		floppyd
.if !empty(PKG_OPTIONS:Mfloppyd)
BUILDLINK_DEPMETHOD.libXt?=	build
.  include "../../x11/libX11/buildlink3.mk"
.  include "../../x11/libXt/buildlink3.mk"
CPPFLAGS+=		-I${X11BASE}/include
CONFIGURE_ARGS+=	--enable-floppyd
PLIST.floppyd=		yes
.else
CONFIGURE_ARGS+=	--disable-floppyd
.endif
