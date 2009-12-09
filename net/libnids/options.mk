# $NetBSD: options.mk,v 1.8 2009/12/09 12:27:28 obache Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.libnids

PKG_OPTIONS_REQUIRED_GROUPS=	libnet
PKG_OPTIONS_GROUP.libnet=	libnet10 libnet11

PKG_SUPPORTED_OPTIONS=		glib

PKG_SUGGESTED_OPTIONS=		libnet10 glib

.include "../../mk/bsd.options.mk"

###
### libnet 1.0.x branch support
###
.if !empty(PKG_OPTIONS:Mlibnet10)
.	include "../../devel/libnet10/buildlink3.mk"
BUILDLINK_DEPMETHOD.libnet10+=	build
.endif

###
### libnet 1.1.x branch support
###
.if !empty(PKG_OPTIONS:Mlibnet11)
.	include "../../devel/libnet11/buildlink3.mk"
BUILDLINK_DEPMETHOD.libnet11+=	build
.endif

###
### glib support
###
.if !empty(PKG_OPTIONS:Mglib)
.include "../../devel/glib2/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-libglib
.endif
