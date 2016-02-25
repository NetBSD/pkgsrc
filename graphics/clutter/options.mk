# $NetBSD: options.mk,v 1.10 2016/02/25 13:37:47 jperkin Exp $
#

PKG_OPTIONS_VAR=	PKG_OPTIONS.clutter
PKG_SUPPORTED_OPTIONS=	introspection x11
PKG_SUGGESTED_OPTIONS=	introspection x11

.include "../../mk/bsd.options.mk"

PLIST_VARS+=	introspection x11 osx

.if !empty(PKG_OPTIONS:Mintrospection)
PLIST.introspection=	yes
BUILDLINK_API_DEPENDS.gobject-introspection+=	gobject-introspection>=0.9.5
BUILDLINK_DEPMETHOD.gobject-introspection+=	build
.include "../../devel/gobject-introspection/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-introspection=yes
.else
CONFIGURE_ARGS+=	--enable-introspection=no
.endif

.if ${OPSYS} == "Darwin"
PLIST.osx=		yes
.endif

.if !empty(PKG_OPTIONS:Mx11)
PLIST.x11=		yes
CONFIGURE_ARGS+=	--enable-x11-backend
CONFIGURE_ARGS+=	--with-imagebackend=gdk-pixbuf
CONFIGURE_ARGS+=	--enable-xinput
BUILDLINK_API_DEPENDS.MesaLib+= MesaLib>=7.0
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXdamage/buildlink3.mk"
BUILDLINK_API_DEPENDS.libXcomposite+=	libXcomposite>=0.4
.include "../../x11/libXcomposite/buildlink3.mk"
.include "../../x11/libXi/buildlink3.mk"
.include "../../graphics/gdk-pixbuf2/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-x
CONFIGURE_ARGS.Darwin+=	--with-quartz-backend
.endif
