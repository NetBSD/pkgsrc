# $NetBSD: options.mk,v 1.3 2024/08/21 11:37:50 markd Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.solid
PKG_SUPPORTED_OPTIONS=		udev
PKG_SUGGESTED_OPTIONS.Linux=	udev

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mudev)
.  include "../../sysutils/libudev/buildlink3.mk"
.else
CMAKE_CONFIGURE_ARGS+=	-DUDEV_DISABLED=ON
.endif
