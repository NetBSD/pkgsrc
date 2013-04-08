# $NetBSD: options.mk,v 1.8 2013/04/08 11:17:13 rodent Exp $

PKG_OPTIONS_VAR=        PKG_OPTIONS.glusterfs
PKG_SUPPORTED_OPTIONS=  georeplication

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mgeoreplication)
CONFIGURE_ARGS+=	--enable-georeplication
PLIST_SRC+=		${PKGDIR}/PLIST.georeplication
.else
CONFIGURE_ARGS+=	--disable-georeplication
.endif
