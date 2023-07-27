# $NetBSD: options.mk,v 1.2 2023/07/27 03:08:20 nia Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.solid
PKG_SUPPORTED_OPTIONS=		udev
PKG_SUGGESTED_OPTIONS.Linux=	udev

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mudev)
.  include "../../sysutils/libudev/buildlink3.mk"
.else
CMAKE_ARGS+=	-DUDEV_DISABLED=ON
.endif
