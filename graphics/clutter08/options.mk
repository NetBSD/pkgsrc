# $NetBSD: options.mk,v 1.1.1.1 2009/10/26 08:30:16 obache Exp $
#

PKG_OPTIONS_VAR=	PKG_OPTIONS.clutter
PKG_SUPPORTED_OPTIONS=	x11
PKG_SUGGESTED_OPTIONS=	x11

.include "../../mk/bsd.options.mk"

PLIST_VARS+=	x11 osx

.if !empty(PKG_OPTIONS:Mx11)
PLIST.x11=		yes
CONFIGURE_ARGS+=	--with-x
CONFIGURE_ARGS+=	--with-flavour=glx
CONFIGURE_ARGS+=	--with-imagebackend=gdk-pixbuf
BUILDLINK_API_DEPENDS.MesaLib+= MesaLib>=7.0
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXdamage/buildlink3.mk"
.include "../../x11/libXfixes/buildlink3.mk"
.include "../../x11/libXcomposite/buildlink3.mk"
.include "../../x11/libXi/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-x
.include "../../mk/bsd.prefs.mk"
.  if ${OPSYS} == Darwin
PLIST.osx=		yes
CONFIGURE_ARGS+=	--with-flavour=osx
CONFIGURE_ARGS+=	--with-imagebackend=quartz
.  endif
.endif
