# $NetBSD: options.mk,v 1.1 2013/11/13 13:27:45 ryoon Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.thunderbird
PKG_SUPPORTED_OPTIONS=	debug mozilla-jemalloc gnome official-mozilla-branding mozilla-lightning mozilla-enigmail
PKG_SUGGESTED_OPTIONS=	mozilla-lightning

PLIST_VARS+=		branding nobranding debug gnome jemalloc

.if ${OPSYS} == "Linux" || ${OPSYS} == "SunOS"
PKG_SUGGESTED_OPTIONS+=	mozilla-jemalloc
.endif

.include "../../mk/bsd.options.mk"

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
CONFIGURE_ARGS+=	--enable-debug --enable-debug-symbols
CONFIGURE_ARGS+=	--disable-install-strip
PLIST.debug=		yes
.else
CONFIGURE_ARGS+=	--disable-debug --disable-debug-symbols
CONFIGURE_ARGS+=	--enable-install-strip
.endif

.if !empty(PKG_OPTIONS:Mmozilla-lightning)
CONFIGURE_ARGS+=	--enable-calendar
PLIST_SRC+=		PLIST.lightning
XPI_FILES+=		${WRKSRC}/mozilla/dist/xpi-stage/calendar-timezones.xpi
XPI_FILES+=		${WRKSRC}/mozilla/dist/xpi-stage/gdata-provider.xpi
XPI_FILES+=		${WRKSRC}/mozilla/dist/xpi-stage/lightning.xpi
.else
CONFIGURE_ARGS+=	--disable-calendar
.endif

.if !empty(PKG_OPTIONS:Mmozilla-enigmail) || make(distinfo)
.include "enigmail.mk"
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
