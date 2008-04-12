# $NetBSD: options.mk,v 1.3 2008/04/12 22:42:58 jlam Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.asterisk
PKG_SUPPORTED_OPTIONS=	zaptel gtk

.include "../../mk/bsd.options.mk"

PLIST_VARS+=		zaptel gtk

.if !empty(PKG_OPTIONS:Mzaptel)
# zaptel only supported under NetBSD at the moment
.  include "../../comms/zaptel-netbsd/buildlink3.mk"
PLIST.zaptel=		yes
.else
MAKE_FLAGS+=		WITHOUT_ZAPTEL=1
.endif

.if !empty(PKG_OPTIONS:Mgtk)
.  include "../../x11/gtk/buildlink3.mk"
MAKE_FLAGS+=		ASTERISK_USE_GTK=1
PLIST.gtk=		yes
.endif
