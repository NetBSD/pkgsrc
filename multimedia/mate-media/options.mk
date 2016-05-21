# $NetBSD: options.mk,v 1.1 2016/05/21 18:58:16 youri Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.mate-media
PKG_SUPPORTED_OPTIONS=	pulseaudio
PKG_SUGGESTED_OPTIONS=	pulseaudio

PLIST_VARS+=	pulse

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mpulseaudio)
.include "../../audio/pulseaudio/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/libunique/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../x11/mate-desktop/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-pulseaudio
PLIST.pulse=	yes
MAKE_DIRS+=	${PKG_SYSCONFDIR}/xdg/autostart
CONF_FILES+=	${PREFIX}/share/examples/mate-media/xdg/autostart/mate-volume-control-applet.desktop \
		${PKG_SYSCONFDIR}/xdg/autostart/mate-volume-control-applet.desktop
.else
CONFIGURE_ARGS+=	--disable-pulseaudio
.endif
