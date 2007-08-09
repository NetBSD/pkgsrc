# $NetBSD: options.mk,v 1.3 2007/08/09 20:28:10 tnn Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.ssh2
PKG_SUPPORTED_OPTIONS=	x11
PKG_SUGGESTED_OPTIONS=	x11

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mx11)
CONFIGURE_ARGS+=	--with-x
PLIST_SUBST+=		X11_SUPPORT=
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libSM/buildlink3.mk"
BUILDLINK_DEPMETHOD.libXt?=	build
.include "../../x11/libXt/buildlink3.mk"
.if ${X11_TYPE} == "modular"
DEPENDS+=		xauth>=1.0.2:../../x11/xauth
CONFIGURE_ENV+=		ac_cv_path_XAUTH_PATH=${PREFIX:Q}/bin/xauth
.endif
.else
CONFIGURE_ARGS+=	--without-x
PLIST_SUBST+=		X11_SUPPORT='@comment '
.endif
