# $NetBSD: options.mk,v 1.7 2013/10/30 06:22:26 dholland Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.celestia
PKG_SUPPORTED_OPTIONS=		lua
PKG_OPTIONS_OPTIONAL_GROUPS=	gui
PKG_OPTIONS_GROUP.gui=		glut gnome gtk kde
PKG_SUGGESTED_OPTIONS=		gtk lua

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mlua)
CONFIGURE_ARGS+=	--with-lua
LUA_VERSIONS_INCOMPATIBLE=52
.  include "../../lang/lua/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-lua
.endif

.if !empty(PKG_OPTIONS:Mglut)
CONFIGURE_ARGS+=	--with-glut
.  include "../../graphics/glut/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mgtk)
CONFIGURE_ARGS+=	--with-gtk
PLIST_SRC=		${PKGDIR}/PLIST.gtk
.  include "../../graphics/gtkglext/buildlink3.mk"
.  include "../../multimedia/libtheora/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mgnome)
CONFIGURE_ARGS+=	--with-gnome
PLIST_SRC=		${PKGDIR}/PLIST.gtk
.  include "../../devel/GConf/schemas.mk"
.  include "../../devel/libgnomeui/buildlink3.mk"
.  include "../../graphics/gtkglext/buildlink3.mk"
.  include "../../multimedia/libtheora/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mkde)
CONFIGURE_ARGS+=	--with-kde
PLIST_SRC=		${PKGDIR}/PLIST.kde
.  include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.  include "../../multimedia/libtheora/buildlink3.mk"
.  include "../../x11/kdelibs3/buildlink3.mk"
.endif

PLIST_SRC+=	${PKGDIR}/PLIST
