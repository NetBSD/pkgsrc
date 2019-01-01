# $NetBSD: options.mk,v 1.1 2019/01/01 18:36:09 nia Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.nestopia
PKG_SUPPORTED_OPTIONS+=		gtk3 jack libao
PKG_SUGGESTED_OPTIONS+=		gtk3 libao

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mgtk3)
CONFIGURE_ARGS+=	--enable-gui
.include "../../x11/gtk3/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mjack)
CONFIGURE_ARGS+=	--with-jack
.include "../../audio/jack/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mlibao)
CONFIGURE_ARGS+=	--with-ao
.include "../../audio/libao/buildlink3.mk"
.endif
