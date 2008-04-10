# $NetBSD: options.mk,v 1.1 2008/04/10 19:34:34 jlam Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.vlc07
PKG_SUPPORTED_OPTIONS=		dvdcss
PKG_OPTIONS_LEGACY_VARS=	WITH_DVDCSS:dvdcss

.include "../../mk/bsd.options.mk"

PLIST_VARS+=		${PKG_SUPPORTED_OPTIONS}

.if !empty(PKG_OPTIONS:Mdvdcss)
.  include "../../multimedia/libdvdcss/buildlink3.mk"
CONFIGURE_ARGS+=	--with-dvdcss=${BUILDLINK_PREFIX.libdvdcss}
PLIST.dvdcss=		yes
.else
CONFIGURE_ARGS+=	--disable-dvd
.endif
