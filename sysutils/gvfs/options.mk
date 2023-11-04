# $NetBSD: options.mk,v 1.6 2023/11/04 12:27:36 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.gvfs
PKG_SUPPORTED_OPTIONS+=	avahi fuse samba
PLIST_VARS+=		${PKG_SUPPORTED_OPTIONS}

.include "../../mk/bsd.fast.prefs.mk"

.if ${OPSYS} == "Linux" || ${OPSYS} == "NetBSD"
PKG_SUGGESTED_OPTIONS+=	samba
.endif

.if ${OPSYS} == "Linux" || (${OPSYS} == "NetBSD" && ${OPSYS_VERSION} > 099993)
PKG_SUGGESTED_OPTIONS+=	fuse
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

.if !empty(PKG_OPTIONS:Mfuse)
BUILDLINK_API_DEPENDS.fuse+=	fuse>=2.8
.include "../../mk/fuse.buildlink3.mk"
CONFIGURE_ARGS+=	--enable-fuse
PLIST.fuse=		yes
.else
CONFIGURE_ARGS+=	--disable-fuse
.endif
