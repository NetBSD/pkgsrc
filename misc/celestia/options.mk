# $NetBSD: options.mk,v 1.11 2023/01/16 03:03:57 dholland Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.celestia
PKG_SUPPORTED_OPTIONS=		lua
PKG_OPTIONS_OPTIONAL_GROUPS=	gui
PKG_OPTIONS_GROUP.gui=		glut gnome gtk
PKG_SUGGESTED_OPTIONS=		gtk lua

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mlua)
CONFIGURE_ARGS+=	--with-lua
LUA_VERSIONS_ACCEPTED=	51
.  include "../../lang/lua/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-lua
.endif

.if !empty(PKG_OPTIONS:Mglut)
CONFIGURE_ARGS+=	--with-glut
.  include "../../graphics/freeglut/buildlink3.mk"
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

PLIST_SRC+=	${PKGDIR}/PLIST
