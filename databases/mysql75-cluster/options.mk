# $NetBSD: options.mk,v 1.1 2022/04/17 04:07:13 jnemeth Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.mysql-cluster

PKG_SUPPORTED_OPTIONS+=	dtrace

.include "../../mk/bsd.options.mk"

# Enable DTrace support
.if !empty(PKG_OPTIONS:Mdtrace)
CMAKE_ARGS+=		-DENABLE_DTRACE=ON
.else
CMAKE_ARGS+=		-DENABLE_DTRACE=OFF
.endif
