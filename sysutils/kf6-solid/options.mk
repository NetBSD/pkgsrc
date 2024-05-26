# $NetBSD: options.mk,v 1.1 2024/05/26 13:00:35 markd Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.solid
PKG_SUPPORTED_OPTIONS=		udev
PKG_SUGGESTED_OPTIONS.Linux=	udev

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mudev)
.  include "../../sysutils/libudev/buildlink3.mk"
.else
CMAKE_ARGS+=	-DUDEV_DISABLED=ON
.endif
