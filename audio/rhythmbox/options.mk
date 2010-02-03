# $NetBSD: options.mk,v 1.2 2010/02/03 12:45:15 drochner Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.rhythmbox
PKG_SUPPORTED_OPTIONS=	hal daap
PKG_SUGGESTED_OPTIONS=	hal
PLIST_VARS+=		hal daap

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mhal)
CONFIGURE_ARGS+=	--with-ipod
.include "../../audio/libgpod/buildlink3.mk"
# needs a newer libmtp
#CONFIGURE_ARGS+=	--with-mtp
#.include "../../devel/libmtp/buildlink3.mk"
CONFIGURE_ARGS+=	--with-hal
PLIST.hal=		yes
.include "../../sysutils/hal/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-hal
.endif

.if !empty(PKG_OPTIONS:Mdaap)
.include "../../net/avahi/buildlink3.mk"
PLIST.daap=		yes
.else
CONFIGURE_ARGS+=	--disable-daap
.endif
