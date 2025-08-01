# $NetBSD: options.mk,v 1.16 2025/08/01 20:58:51 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.dbus
PKG_SUPPORTED_OPTIONS+=	x11
PKG_SUGGESTED_OPTIONS=	x11

.if ${OPSYS} == "NetBSD"  ||	\
    ${OPSYS} == "FreeBSD" ||	\
    ${OPSYS} == "OpenBSD" ||	\
    ${OPSYS} == "Darwin"  ||	\
    ${OPSYS} == "DragonFly"
PKG_SUPPORTED_OPTIONS+=	kqueue
PKG_SUGGESTED_OPTIONS+=	kqueue
.endif

PLIST_VARS+=		launchd
# We may want to make it SUGGESTED once we have a framework for
# launchd support. See PR/49591.
PKG_SUPPORTED_OPTIONS.Darwin+=	launchd

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mkqueue)
MESON_ARGS+=		-Dkqueue=enabled
.else
MESON_ARGS+=		-Dkqueue=disabled
.endif

.if !empty(PKG_OPTIONS:Mx11)
MESON_ARGS+=		-Dx11_autolaunch=enabled
.  include "../../x11/libX11/buildlink3.mk"
.  include "../../x11/libXt/buildlink3.mk"
.else
MESON_ARGS+=		-Dx11_autolaunch=disabled
.endif

.if !empty(PKG_OPTIONS:Mlaunchd)
MESSAGE_SRC+=			MESSAGE.launchd
PLIST.launchd=			yes
MESON_ARGS+=			-Dlaunchd=enabled
MESON_ARGS+=			-Dlaunchd_agent_dir=${PREFIX}/Library/LaunchAgents
.else
MESON_ARGS+=			-Dlaunchd=disabled
.endif
