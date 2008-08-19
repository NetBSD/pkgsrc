# $NetBSD: options.mk,v 1.8 2008/08/19 18:10:22 tron Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.pango
PKG_SUPPORTED_OPTIONS=	x11
PKG_SUGGESTED_OPTIONS=	x11

.include "../../mk/bsd.options.mk"

PLIST_VARS+=		x11

###
### X11 support
###
.if !empty(PKG_OPTIONS:Mx11)
# fix for pangox.pc
CONFIGURE_ENV+=		X_EXTRA_LIBS=${COMPILER_RPATH_FLAG}${X11BASE}/lib
PLIST.x11=		yes
.include "../../x11/libXft/buildlink3.mk"
.include "../../x11/libXrender/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
BUILDLINK_DEPMETHOD.libXt?=	build # only for configure
.include "../../x11/libXt/buildlink3.mk"

.if ${OPSYS} == "Darwin"
CONFIGURE_ENV+=	ac_cv_header_Carbon_Carbon_h=no
.endif
.else
CONFIGURE_ARGS+=	--without-x

.if ${OPSYS} == "Darwin"
PLIST.carbon=	yes
.endif
.endif
