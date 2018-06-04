# $NetBSD: options.mk,v 1.3 2018/06/04 12:35:51 youri Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.mate-media
PKG_SUPPORTED_OPTIONS=	pulseaudio
PKG_SUGGESTED_OPTIONS=

PLIST_VARS+=	pulse

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mpulseaudio)
.include "../../audio/pulseaudio/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-pulseaudio
PLIST.pulse=	yes
MAKE_DIRS+=	${PKG_SYSCONFDIR}/xdg/autostart
CONF_FILES+=	${PREFIX}/share/examples/mate-media/xdg/autostart/mate-volume-control-applet.desktop \
		${PKG_SYSCONFDIR}/xdg/autostart/mate-volume-control-applet.desktop
.else
CONFIGURE_ARGS+=	--disable-pulseaudio
.endif
