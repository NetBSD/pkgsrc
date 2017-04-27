# $NetBSD: options.mk,v 1.19 2017/04/27 13:32:40 ryoon Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.thunderbird

PKG_OPTIONS_REQUIRED_GROUPS=	gtk
PKG_OPTIONS_GROUP.gtk=		gtk2 gtk3
PKG_SUGGESTED_OPTIONS=		gtk3

PKG_SUPPORTED_OPTIONS=	alsa debug mozilla-jemalloc gnome \
			official-mozilla-branding pulseaudio \
			mozilla-lightning
PKG_SUGGESTED_OPTIONS+=	mozilla-lightning

PLIST_VARS+=		branding nobranding debug gnome jemalloc

PKG_SUGGESTED_OPTIONS.Linux+=	alsa mozilla-jemalloc
PKG_SUGGESTED_OPTIONS.*+=	pulseaudio

.include "../../mk/bsd.options.mk"

PLIST_VARS+=		gtk3
.if !empty(PKG_OPTIONS:Mgtk2)
CONFIGURE_ARGS+=	--enable-default-toolkit=cairo-gtk2
BUILDLINK_API_DEPENDS.gtk2+=  gtk2+>=2.18.3nb1
.include "../../x11/gtk2/buildlink3.mk"
.endif

# As of firefox-51 gtk2 is still pulled in implicitly
.if !empty(PKG_OPTIONS:Mgtk3)
CONFIGURE_ARGS+=	--enable-default-toolkit=cairo-gtk3
# gtk2 needed even if --enable-default-toolkit=cairo-gtk3
BUILDLINK_API_DEPENDS.gtk2+=  gtk2+>=2.18.3nb1
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
PLIST.gtk3=		yes
.endif

.if !empty(PKG_OPTIONS:Malsa)
CONFIGURE_ARGS+=	--enable-alsa
.include "../../audio/alsa-lib/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-alsa
.endif

.if !empty(PKG_OPTIONS:Mgnome)
.include "../../devel/libgnomeui/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-dbus --enable-gnomeui
PLIST.gnome=		yes
.else
CONFIGURE_ARGS+=	--disable-dbus --disable-gnomeui
.endif

.if !empty(PKG_OPTIONS:Mmozilla-jemalloc)
PLIST.jemalloc=		yes
CONFIGURE_ARGS+=	--enable-jemalloc
.else
CONFIGURE_ARGS+=	--disable-jemalloc
.endif

.if !empty(PKG_OPTIONS:Mdebug)
CONFIGURE_ARGS+=	--enable-debug --enable-debug-symbols --disable-optimize
CONFIGURE_ARGS+=	--disable-install-strip
PLIST.debug=		yes
.else
CONFIGURE_ARGS+=	--disable-debug
CONFIGURE_ARGS+=	--enable-optimize=-O2
CONFIGURE_ARGS+=	--enable-install-strip
BUILDLINK_TRANSFORM+=	rm:-g
.endif

.if !empty(PKG_OPTIONS:Mpulseaudio)
.include "../../audio/pulseaudio/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-pulseaudio
.else
CONFIGURE_ARGS+=	--disable-pulseaudio
.endif

.if !empty(PKG_OPTIONS:Mmozilla-lightning)
CONFIGURE_ARGS+=	--enable-calendar
PLIST_SRC+=		PLIST.lightning
XPI_FILES+=		${WRKSRC}/${OBJDIR}/dist/xpi-stage/gdata-provider.xpi
XPI_FILES+=		${WRKSRC}/${OBJDIR}/dist/xpi-stage/lightning.xpi
.else
CONFIGURE_ARGS+=	--disable-calendar
.endif

.if !empty(PKG_OPTIONS:Mofficial-mozilla-branding)
CONFIGURE_ARGS+=	--enable-official-branding
PLIST.branding=		yes
LICENSE=		mozilla-trademark-license
RESTRICTED=		Trademark holder prohibits distribution of modified versions.
NO_BIN_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_FTP=		${RESTRICTED}
.else
CONFIGURE_ARGS+=	--disable-official-branding
PLIST.nobranding=	yes
.endif
