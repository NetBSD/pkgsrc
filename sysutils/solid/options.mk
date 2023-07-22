# $NetBSD: options.mk,v 1.1 2023/07/22 08:32:34 nia Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.solid
PKG_SUPPORTED_OPTIONS=		udev

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mudev)
.  include "../../sysutils/libudev/buildlink3.mk"
.else
CMAKE_ARGS+=	-DUDEV_DISABLED=ON
.endif
