# $NetBSD: options.mk,v 1.1 2019/05/13 16:17:51 adam Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.inkscape
PKG_SUPPORTED_OPTIONS=	gnome

.include "../../mk/bsd.options.mk"

# gnome-vfs support for the inkscape file open window.
.if !empty(PKG_OPTIONS:Mgnome)
CMAKE_ARGS+=		-DWITH_GNOME_VFS=ON
.include "../../sysutils/gnome-vfs/buildlink3.mk"
.else
CMAKE_ARGS+=		-DWITH_GNOME_VFS=OFF
.endif
