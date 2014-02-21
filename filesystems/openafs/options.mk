# $NetBSD: options.mk,v 1.3 2014/02/21 21:33:51 gendalia Exp $

.include "../../mk/bsd.prefs.mk"

PKG_OPTIONS_VAR=        PKG_OPTIONS.openafs
PKG_SUPPORTED_OPTIONS+= server bitmap-later kernel-module supergroups namei
.if ${MACHINE_ARCH} != "x86_64"
PKG_SUPPORTED_OPTIONS+= pam
.endif
PKG_SUGGESTED_OPTIONS=  server -bitmap-later namei -kernel-module supergroups

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
.if !empty(PKG_OPTIONS:Mpam)
CONFIGURE_ARGS+=        --enable-pam
.include "../../mk/pam.buildlink3.mk"
PLIST_SRC+=             ${.CURDIR}/PLIST.pam
.else
CONFIGURE_ARGS+=        --disable-pam
.endif
