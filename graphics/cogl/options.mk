# $NetBSD: options.mk,v 1.1.4.1 2014/02/05 14:25:40 tron Exp $
#

PKG_OPTIONS_VAR=	PKG_OPTIONS.cogl
PKG_SUPPORTED_OPTIONS=	introspection x11
PKG_SUGGESTED_OPTIONS=	x11

.include "../../mk/bsd.options.mk"

PLIST_VARS+=	introspection x11

.if !empty(PKG_OPTIONS:Mintrospection)
PLIST.introspection=		yes
BUILDLINK_API_DEPENDS.gobject-introspection+=	gobject-introspection>=0.9.5
BUILDLINK_DEPMETHOD.gobject-introspection+=	build
.include "../../devel/gobject-introspection/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-introspection=yes
.else
CONFIGURE_ARGS+=	--enable-introspection=no
.endif

.if !empty(PKG_OPTIONS:Mx11)
PLIST.x11=		yes
CONFIGURE_ARGS+=	--with-x
CONFIGURE_ARGS+=	--enable-gdk-pixbuf
CONFIGURE_ARGS+=	--with-gl-libname=libGL
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXdamage/buildlink3.mk"
.include "../../x11/libXfixes/buildlink3.mk"
.include "../../x11/libXcomposite/buildlink3.mk"
.include "../../x11/libXrandr/buildlink3.mk"
.include "../../graphics/gdk-pixbuf2/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-x
.include "../../mk/bsd.prefs.mk"
.  if ${OPSYS} == Darwin
PLIST.osx=		yes
CONFIGURE_ARGS+=	--with-quartz-image
.  endif
.endif
