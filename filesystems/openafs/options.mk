# $NetBSD: options.mk,v 1.6 2024/10/10 14:04:05 jakllsch Exp $

.include "../../mk/bsd.prefs.mk"

PKG_OPTIONS_VAR=	PKG_OPTIONS.openafs
PKG_SUPPORTED_OPTIONS+=	server bitmap-later kernel-module supergroups namei
PKG_SUPPORTED_OPTIONS+=	openafs-kauth
PKG_SUGGESTED_OPTIONS=	server namei supergroups

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Msupergroups)
CONFIGURE_ARGS+=        --enable-supergroups
.endif
.if !empty(PKG_OPTIONS:Mbitmap-later)
CONFIGURE_ARGS+=        --enable-bitmap-later
.endif
.if !empty(PKG_OPTIONS:Mkernel-module)
CONFIGURE_ARGS+=        --enable-kernel-module
.else
CONFIGURE_ARGS+=        --disable-kernel-module
.endif
.if !empty(PKG_OPTIONS:Mnamei)
CONFIGURE_ARGS+=        --enable-namei-fileserver
.endif
.if !empty(PKG_OPTIONS:Mopenafs-kauth)
CONFIGURE_ARGS+=        --enable-kauth
.include "../../mk/pam.buildlink3.mk"
PLIST_SRC+=             ${.CURDIR}/PLIST.kauth
.else
CONFIGURE_ARGS+=        --disable-kauth
.endif
