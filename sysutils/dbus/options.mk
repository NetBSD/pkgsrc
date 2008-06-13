# $NetBSD: options.mk,v 1.1 2008/06/13 11:28:35 drochner Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.dbus
PKG_SUPPORTED_OPTIONS+=	debug kqueue nox11
PKG_SUGGESTED_OPTIONS=	# empty

.if (${OPSYS} == "NetBSD"  ||	\
     ${OPSYS} == "FreeBSD" ||	\
     ${OPSYS} == "OpenBSD")
PKG_SUGGESTED_OPTIONS+=	kqueue
.endif

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mdebug)
CONFIGURE_ARGS.enable+=	asserts tests verbose-mode
.endif

.if !empty(PKG_OPTIONS:Mkqueue)
CONFIGURE_ARGS.enable+= 	kqueue
.else
CONFIGURE_ARGS.disable+=	kqueue
.endif

.if !empty(PKG_OPTIONS:Mnox11)
CONFIGURE_ARGS.without=	x
.else
CONFIGURE_ARGS.with+=	x
.  include "../../x11/libX11/buildlink3.mk"
BUILDLINK_DEPMETHOD.libXt=	build
.  include "../../x11/libXt/buildlink3.mk"
.endif
