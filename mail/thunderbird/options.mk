# $NetBSD: options.mk,v 1.7 2011/08/19 14:39:09 tnn Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.thunderbird
PKG_SUPPORTED_OPTIONS=	debug mozilla-jemalloc gnome official-mozilla-branding mozilla-lightning mozilla-enigmail
PKG_SUGGESTED_OPTIONS=	mozilla-lightning

PLIST_VARS+=		branding nobranding debug gnome

.if ${OPSYS} == "Linux" || ${OPSYS} == "SunOS"
PKG_SUGGESTED_OPTIONS+=	mozilla-jemalloc
.endif

.if !empty(MACHINE_ARCH:Mi386) || !empty(MACHINE_ARCH:Msparc) || \
	!empty(MACHINE_ARCH:Marm) || !empty(MACHINE_ARCH:Mx86_64)
PKG_SUPPORTED_OPTIONS+=	mozilla-jit
PKG_SUGGESTED_OPTIONS+=	mozilla-jit
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
CONFIGURE_ARGS+=	--enable-jemalloc
.else
CONFIGURE_ARGS+=	--disable-jemalloc
.endif

.if !empty(PKG_OPTIONS:Mdebug)
CONFIGURE_ARGS+=	--enable-debug
PLIST.debug=		yes
.else
CONFIGURE_ARGS+=	--disable-debug
.endif

.if !empty(PKG_OPTIONS:Mmozilla-jit)
CONFIGURE_ARGS+=	--enable-jit
.else
CONFIGURE_ARGS+=	--disable-jit
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
