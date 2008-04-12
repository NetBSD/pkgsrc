# $NetBSD: options.mk,v 1.4 2008/04/12 22:43:12 jlam Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.ssh2
PKG_SUPPORTED_OPTIONS=	x11
PKG_SUGGESTED_OPTIONS=	x11

.include "../../mk/bsd.options.mk"

PLIST_VARS+=		x11

.if !empty(PKG_OPTIONS:Mx11)
CONFIGURE_ARGS+=	--with-x
PLIST.x11=		yes
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
.endif
