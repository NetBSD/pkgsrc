# $NetBSD: options.mk,v 1.3 2014/10/22 19:42:48 gls Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.mpv
PKG_SUPPORTED_OPTIONS=	caca lua pulseaudio sdl v4l2 quvi
PKG_SUGGESTED_OPTIONS=	lua

.include "../../mk/bsd.options.mk"

###
### caca support (video output)
###
.if !empty(PKG_OPTIONS:Mcaca)
WAF_CONFIGURE_ARGS+=	--enable-caca
.include "../../graphics/libcaca/buildlink3.mk"
.else
WAF_CONFIGURE_ARGS+=	--disable-caca
.endif

###
### lua support
###
.if !empty(PKG_OPTIONS:Mlua)
WAF_CONFIGURE_ARGS+=	--enable-lua
.include "../../lang/lua/buildlink3.mk"
.else
WAF_CONFIGURE_ARGS+=	--disable-lua
.endif

###
### Pulseaudio support (audio output)
###
.if !empty(PKG_OPTIONS:Mpulseaudio)
WAF_CONFIGURE_ARGS+=	--enable-pulse
.include "../../audio/pulseaudio/buildlink3.mk"
.else
WAF_CONFIGURE_ARGS+=	--disable-pulse
.endif

###
### SDL support (audio output)
###
.if !empty(PKG_OPTIONS:Msdl)
WAF_CONFIGURE_ARGS+=	--enable-sdl1
.include "../../devel/SDL/buildlink3.mk"
.else
WAF_CONFIGURE_ARGS+=	--disable-sdl1
.endif

###
### V4L2 support
###
.if !empty(PKG_OPTIONS:Mv4l2)
WAF_CONFIGURE_ARGS+=	--enable-libv4l2
.else
WAF_CONFIGURE_ARGS+=	--disable-libv4l2
.endif

###
### Quvi (Youtube) support
###
.if !empty(PKG_OPTIONS:Mquvi)
WAF_CONFIGURE_ARGS+=    --enable-libquvi4
.include "../../net/libquvi/buildlink3.mk"
.else
WAF_CONFIGURE_ARGS+=    --disable-libquvi4
.endif
