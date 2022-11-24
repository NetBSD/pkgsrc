# $NetBSD: options.mk,v 1.16 2022/11/24 12:56:03 adam Exp $

.include "../../comms/lirc/available.mk"

PKG_OPTIONS_VAR=	PKG_OPTIONS.pulseaudio
PKG_SUPPORTED_OPTIONS=	avahi gsettings x11
.if ${LIRC_AVAILABLE} == "yes"
PKG_SUPPORTED_OPTIONS+=	lirc
.endif
PKG_SUGGESTED_OPTIONS=	avahi x11
PLIST_VARS+=		avahi gsettings x11 lirc

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mavahi)
.include "../../net/avahi/buildlink3.mk"
PLIST.avahi=		yes
.else
MESON_ARGS+=		-Davahi=disabled
.endif

.if !empty(PKG_OPTIONS:Mgsettings)
PLIST.gsettings=	yes
MESON_ARGS+=		-Dgsettings=enabled
.else
MESON_ARGS+=		-Dgsettings=disabled
.endif

.if !empty(PKG_OPTIONS:Mlirc)
PLIST.lirc=		yes
CONFIGURE_ARGS+=	--enable-lirc
.include "../../comms/lirc/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-lirc
.endif

.if !empty(PKG_OPTIONS:Mx11)
.include "../../x11/libICE/buildlink3.mk"
.include "../../x11/libSM/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXtst/buildlink3.mk"
.include "../../x11/xorgproto/buildlink3.mk"
PLIST.x11=		yes
.else
CONFIGURE_ARGS+=	--disable-x11
.endif

PRINT_PLIST_AWK+=	{if ($$0 ~ /x11/ && !($$0 ~ /start-pulseaudio-x11.1/)) {$$0 = "$${PLIST.x11}" $$0;}}
PRINT_PLIST_AWK+=	{if ($$0 ~ /pulseaudio.desktop/) {$$0 = "$${PLIST.x11}" $$0;}}

PRINT_PLIST_AWK+=	{if ($$0 ~ /avahi/) {$$0 = "$${PLIST.avahi}" $$0;}}
PRINT_PLIST_AWK+=	{if ($$0 ~ /zeroconf/) {$$0 = "$${PLIST.avahi}" $$0;}}
PRINT_PLIST_AWK+=	{if ($$0 ~ /module-raop-discover/) {$$0 = "$${PLIST.avahi}" $$0;}}

PRINT_PLIST_AWK+=	{if ($$0 ~ /oss/) {$$0 = "$${PLIST.oss}" $$0;}}
PRINT_PLIST_AWK+=	{if ($$0 ~ /dsp/ && !($$0 ~ /share\/bash-completion\/completions\/padsp/)) {$$0 = "$${PLIST.oss}" $$0;}}
