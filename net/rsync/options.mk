# $NetBSD: options.mk,v 1.6 2023/11/10 10:01:37 nia Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.rsync

PKG_SUPPORTED_OPTIONS=	acl zstd
PKG_SUGGESTED_OPTIONS=	acl

.include "../../mk/bsd.prefs.mk"

.if !${MACHINE_PLATFORM:MDarwin-*-powerpc*}
PKG_SUGGESTED_OPTIONS+=	zstd
.endif

.include "../../mk/bsd.options.mk"

.if empty(PKG_OPTIONS:Macl)
CONFIGURE_ARGS+=       --disable-acl-support
.endif

.if !empty(PKG_OPTIONS:Mzstd)
.include "../../archivers/zstd/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-zstd
.else
CONFIGURE_ARGS+=	--disable-zstd
.endif
