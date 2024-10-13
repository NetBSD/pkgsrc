# $NetBSD: options.mk,v 1.3 2024/10/13 14:13:22 gdt Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.mosquitto
PKG_SUPPORTED_OPTIONS=	websockets
PKG_SUGGESTED_OPTIONS=	websockets

.include "../../mk/bsd.options.mk"

# \todo With websockets, mosquitto's build system throws warnings that
# performance will be terrible.  Figure out if this is correct or not
# and fix or file bugs as appropriate.
.if !empty(PKG_OPTIONS:Mwebsockets)
CMAKE_CONFIGURE_ARGS+=	-DWITH_WEBSOCKETS=yes
.include "../../www/libwebsockets/buildlink3.mk"
.else
CMAKE_CONFIGURE_ARGS+=	-DWITH_WEBSOCKETS=no
.endif
