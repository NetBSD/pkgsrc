# $NetBSD: options.mk,v 1.2 2016/02/26 09:41:07 jperkin Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.tor-browser
PKG_SUPPORTED_OPTIONS+=	alsa debug debug-info mozilla-jemalloc pulseaudio
PLIST_VARS+=		debug

PKG_SUGGESTED_OPTIONS.Linux+=	alsa mozilla-jemalloc
PKG_SUGGESTED_OPTIONS.*+=	pulseaudio

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Malsa)
CONFIGURE_ARGS+=	--enable-alsa
.include "../../audio/alsa-lib/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-alsa
.endif

.if !empty(PKG_OPTIONS:Mmozilla-jemalloc)
PLIST.jemalloc=		yes
CONFIGURE_ARGS+=	--enable-jemalloc
.else
CONFIGURE_ARGS+=	--disable-jemalloc
.endif

.include "../../mk/compiler.mk"
.if !empty(PKGSRC_COMPILER:Mgcc)
.if ${CC_VERSION:S/gcc-//:S/.//g} >= 480
# Modern gcc does not run any "tracking" passes when compiling with -O0,
# which makes the generated debug info mostly useless. So explicitly
# request them.
O0TRACKING=-fvar-tracking-assignments -fvar-tracking
.endif
.endif

.if !empty(PKG_OPTIONS:Mdebug)
CONFIGURE_ARGS+=	--enable-debug="-g -O0 ${O0TRACKING}" --enable-debug-symbols --disable-optimize
CONFIGURE_ARGS+=	--disable-install-strip
PLIST.debug=		yes
.else
.if !empty(PKG_OPTIONS:Mdebug-info)
CONFIGURE_ARGS+=	--enable-debug-symbols
.else
CONFIGURE_ARGS+=	--disable-debug-symbols
.endif
CONFIGURE_ARGS+=	--disable-debug
CONFIGURE_ARGS+=	--enable-optimize=-O2
CONFIGURE_ARGS+=	--enable-install-strip
.endif

.if !empty(PKG_OPTIONS:Mpulseaudio)
.include "../../audio/pulseaudio/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-pulseaudio
.else
CONFIGURE_ARGS+=	--disable-pulseaudio
.endif
# XXX end
