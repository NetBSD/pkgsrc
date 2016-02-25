# $NetBSD: options.mk,v 1.2 2016/02/25 15:00:51 jperkin Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.thunderbird31
PKG_SUPPORTED_OPTIONS=	alsa debug mozilla-jemalloc gnome \
			official-mozilla-branding pulseaudio \
			mozilla-lightning
PKG_SUGGESTED_OPTIONS=	mozilla-lightning

PLIST_VARS+=		branding nobranding debug gnome jemalloc

PKG_SUGGESTED_OPTIONS.Linux+=	alsa mozilla-jemalloc
PKG_SUGGESTED_OPTIONS.*+=	pulseaudio

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Malsa)
CONFIGURE_ARGS+=	--enable-alsa
.include "../../audio/alsa-lib/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-alsa
.endif

.if !empty(PKG_OPTIONS:Mgnome)
.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../sysutils/gnome-vfs/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-gnomevfs --enable-dbus --enable-gnomeui
PLIST.gnome=		yes
.else
CONFIGURE_ARGS+=	--disable-gnomevfs --disable-dbus --disable-gnomeui
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
XPI_FILES+=		${WRKSRC}/${OBJDIR}/mozilla/dist/xpi-stage/gdata-provider.xpi
XPI_FILES+=		${WRKSRC}/${OBJDIR}/mozilla/dist/xpi-stage/lightning.xpi
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
