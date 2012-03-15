# $NetBSD: options.mk,v 1.1.1.1 2012/03/15 08:58:27 ryoon Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.xulrunner
PKG_SUPPORTED_OPTIONS=	debug mozilla-jemalloc gnome pulseaudio

PLIST_VARS+=	jit gnome jemalloc debug

.if ${OPSYS} == "Linux" || ${OPSYS} == "SunOS"
PKG_SUGGESTED_OPTIONS+=	mozilla-jemalloc
.endif

.if !empty(MACHINE_ARCH:Mi386) || !empty(MACHINE_ARCH:Msparc*) || \
	!empty(MACHINE_ARCH:Marm) || !empty(MACHINE_ARCH:Mx86_64)
PKG_SUPPORTED_OPTIONS+=	mozilla-jit
PKG_SUGGESTED_OPTIONS+=	mozilla-jit
NANOJIT_ARCH.i386=	i386
NANOJIT_ARCH.arm=	ARM
NANOJIT_ARCH.sparc=	Sparc
NANOJIT_ARCH.sparc64=	Sparc
NANOJIT_ARCH.x86_64=	X64
.endif

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mgnome)
.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../sysutils/gnome-vfs/buildlink3.mk"
.include "../../sysutils/libnotify/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-gnomevfs --enable-dbus --enable-gnomeui
CONFIGURE_ARGS+=	--enable-libnotify
PLIST.gnome=		yes
.else
CONFIGURE_ARGS+=	--disable-gnomevfs --disable-dbus --disable-gnomeui
CONFIGURE_ARGS+=	--disable-libnotify
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

.if !empty(PKG_OPTIONS:Mmozilla-jit)
PLIST.jit=		yes
PLIST_SUBST+=		NANOJIT_ARCH=${NANOJIT_ARCH.${MACHINE_ARCH}}
CONFIGURE_ARGS+=	--enable-tracejit
.else
CONFIGURE_ARGS+=	--disable-tracejit
.endif

.if !empty(PKG_OPTIONS:Mpulseaudio)
.include "../../audio/pulseaudio/buildlink3.mk"
ALL_ENV+=	PKGSRC_PULSEAUDIO=1
.endif
