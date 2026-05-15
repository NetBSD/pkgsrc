# $NetBSD: options.mk,v 1.7 2026/05/15 17:00:59 wiz Exp $
#

PKG_OPTIONS_VAR=	PKG_OPTIONS.input-pad
PKG_SUPPORTED_OPTIONS=	eekboard introspection xtest
PKG_SUGGESTED_OPTIONS=	xtest

PKG_SUGGESTED_OPTIONS+=	${${USE_CROSS_COMPILE:tl} == "yes":?:introspection}

.include "../../mk/bsd.options.mk"

PLIST_VARS+=	eek introspection xtest

#
# Draw keyboard using libeek
#
.if !empty(PKG_OPTIONS:Meekboard)
.include "../../x11/eekboard/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-eek
PLIST.eek=		yes
.endif

#
# Send keyboard event with xtest
#
.if !empty(PKG_OPTIONS:Mxtest)
.include "../../x11/libXtst/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-xtest=yes
PLIST.xtest=		yes
.endif

#
# Introspection support
#
.if !empty(PKG_OPTIONS:Mintrospection)
TOOL_DEPENDS+=		glib2-introspection-[0-9]*:../../devel/glib2-introspection
BUILDLINK_DEPMETHOD.gobject-introspection=	build
.include "../../devel/gobject-introspection/buildlink3.mk"
PLIST.introspection=	yes
.endif
