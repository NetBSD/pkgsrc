# $NetBSD: options.mk,v 1.4 2026/11/25 14:42:04 wiz Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.emulationstation
PKG_OPTIONS_REQUIRED_GROUPS=	graphics
PKG_OPTIONS_GROUP.graphics=	opengl

.include "../../mk/bsd.fast.prefs.mk"

.if ${MACHINE_ARCH:M*arm*}
PKG_OPTIONS_GROUP.graphics+=	rpi
PKG_SUGGESTED_OPTIONS+=		rpi
.else
PKG_SUGGESTED_OPTIONS+=		opengl
.endif

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mrpi)
.include "../../misc/raspberrypi-userland/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mopengl)
.include "../../mk/mesa.buildlink3.mk"
.endif
