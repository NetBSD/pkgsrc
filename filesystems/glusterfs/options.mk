# $NetBSD: options.mk,v 1.2 2011/08/09 07:15:42 manu Exp $

PKG_OPTIONS_VAR=        PKG_OPTIONS.glusterfs
PKG_SUPPORTED_OPTIONS=  georeplication

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mgeoreplication)
CONFIGURE_ARGS+=	--enable-georeplication
PLIST_SRC+=		${PKGDIR}/PLIST.georeplication
.endif
