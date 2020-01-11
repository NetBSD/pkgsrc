# $NetBSD: options.mk,v 1.1 2020/01/11 15:18:46 nia Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.imv
PKG_SUPPORTED_OPTIONS=	svg wayland x11

.include "../../devel/wayland/platform.mk"
.if ${PLATFORM_SUPPORTS_WAYLAND} == "yes"
PKG_SUGGESTED_OPTIONS=	svg wayland x11
.else
PKG_SUGGESTED_OPTIONS=	svg x11
.endif

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Msvg)
.  include "../../graphics/librsvg/buildlink3.mk"
MAKE_FLAGS+=		BACKEND_LIBRSVG="yes"
.else
MAKE_FLAGS+=		BACKEND_LIBRSVG="no"
.endif

PLIST_VARS+=		all
.if !empty(PKG_OPTIONS:Mwayland) && !empty(PKG_OPTIONS:Mx11)
PLIST.all=		yes
MAKE_FLAGS+=		WINDOWS="all"
.elif !empty(PKG_OPTIONS:Mwayland)
MAKE_FLAGS+=		WINDOWS="wayland"
.elif !empty(PKG_OPTIONS:Mx11)
MAKE_FLAGS+=		WINDOWS="x11"
.else
PKG_FAIL_REASON+=	"Must select at least one windowing system"
.endif

.if !empty(PKG_OPTIONS:Mwayland)
.  include "../../devel/wayland/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mx11)
.  include "../../graphics/glu/buildlink3.mk"
.  include "../../x11/libxcb/buildlink3.mk"
.  include "../../x11/libX11/buildlink3.mk"
.endif
