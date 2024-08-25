# $NetBSD: options.mk,v 1.2 2024/08/25 06:18:30 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.mysql-cluster

PKG_SUPPORTED_OPTIONS+=	dtrace

.include "../../mk/bsd.options.mk"

# Enable DTrace support
.if !empty(PKG_OPTIONS:Mdtrace)
CMAKE_CONFIGURE_ARGS+=		-DENABLE_DTRACE=ON
.else
CMAKE_CONFIGURE_ARGS+=		-DENABLE_DTRACE=OFF
.endif
