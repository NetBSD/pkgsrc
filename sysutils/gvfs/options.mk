# $NetBSD: options.mk,v 1.1 2022/04/21 16:41:26 nia Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.gvfs
PKG_SUPPORTED_OPTIONS+=	avahi hal fuse samba
PKG_SUGGESTED_OPTIONS+=	samba
PLIST_VARS+=		${PKG_SUPPORTED_OPTIONS}

.include "../../mk/bsd.fast.prefs.mk"

# XXX fuse.bl3.mk will fail if we include it and fuse is not available
.if ${OPSYS} == "Linux" || (${OPSYS} == "NetBSD" && exists(/usr/include/fuse.h))
PKG_SUGGESTED_OPTIONS=+	fuse
.endif

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mavahi)
.include "../../net/avahi/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-avahi
PLIST.avahi=		yes
.else
CONFIGURE_ARGS+=	--disable-avahi
.endif

.if !empty(PKG_OPTIONS:Msamba)
CONFIGURE_ARGS+=	--with-samba-includes=${BUILDLINK_PREFIX.samba}/include
CONFIGURE_ARGS+=	--with-samba-libs=${BUILDLINK_PREFIX.samba}/lib
.include "../../net/samba4/buildlink3.mk"
PLIST.samba=		yes
.else
CONFIGURE_ARGS+=	--disable-samba
.endif

.if !empty(PKG_OPTIONS:Mhal)
.include "../../misc/libcdio-paranoia/buildlink3.mk"
.include "../../sysutils/hal/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-hal
CONFIGURE_ARGS+=	--enable-cdda
PLIST.hal=		yes
.else
CONFIGURE_ARGS+=	--disable-hal
CONFIGURE_ARGS+=	--disable-cdda
.endif

.if !empty(PKG_OPTIONS:Mfuse)
.include "../../mk/fuse.buildlink3.mk"
CONFIGURE_ARGS+=	--enable-fuse
PLIST.fuse=		yes
.else
CONFIGURE_ARGS+=	--disable-fuse
.endif


