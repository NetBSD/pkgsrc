# $NetBSD: options.mk,v 1.10 2016/02/26 10:24:12 jperkin Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.dbus
PKG_SUPPORTED_OPTIONS+=	debug x11
PKG_SUGGESTED_OPTIONS=	x11

.if (${OPSYS} == "NetBSD"  ||	\
     ${OPSYS} == "FreeBSD" ||	\
     ${OPSYS} == "OpenBSD" ||	\
     ${OPSYS} == "Darwin" ||	\
     ${OPSYS} == "DragonFly")
PKG_SUPPORTED_OPTIONS+=	kqueue
PKG_SUGGESTED_OPTIONS+=	kqueue
.endif

# We may want to make it SUGGESTED once we have a framework for
# launchd support. See PR/49591.
PKG_SUPPORTED_OPTIONS.Darwin+=	launchd

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mdebug)
CONFIGURE_ARGS+=	--enable-asserts
CONFIGURE_ARGS+=	--enable-verbose-mode
.else
CONFIGURE_ARGS+=	--disable-asserts
CONFIGURE_ARGS+=	--disable-verbose-mode
.endif

.if !empty(PKG_OPTIONS:Mkqueue)
CONFIGURE_ARGS+= 	--enable-kqueue
.else
CONFIGURE_ARGS+=	--disable-kqueue
.endif

.if !empty(PKG_OPTIONS:Mx11)
CONFIGURE_ARGS+=	--with-x
.  include "../../x11/libX11/buildlink3.mk"
BUILDLINK_DEPMETHOD.libXt=	build
.  include "../../x11/libXt/buildlink3.mk"
.else
CONFIGURE_ARGS=		--without-x
.endif

.if !empty(PKG_OPTIONS:Mlaunchd)
MESSAGE_SRC+=			MESSAGE.launchd
PLIST.launchd=			yes
CONFIGURE_ARGS+=		--enable-launchd
CONFIGURE_ARGS+=		--with-launchd-agent-dir=${PREFIX}/Library/LaunchAgents
.else
CONFIGURE_ARGS+=		--disable-launchd
.endif
