# $NetBSD: options.mk,v 1.4 2013/10/23 12:31:14 obache Exp $
#

PKG_OPTIONS_VAR=	PKG_OPTIONS.input-pad
PKG_SUPPORTED_OPTIONS=	eekboard introspection xtest
PKG_SUGGESTED_OPTIONS=	introspection

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
BUILDLINK_DEPMETHOD.gobject-introspection=	build
.include "../../devel/gobject-introspection/buildlink3.mk"
PLIST.introspection=	yes
.endif
