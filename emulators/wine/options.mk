# $NetBSD: options.mk,v 1.16 2017/05/19 13:18:17 prlw1 Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.wine
PKG_SUPPORTED_OPTIONS=	cups dbus esound hal ldap opengl sane ssl x11
PKG_SUGGESTED_OPTIONS=	opengl ssl x11

.include "../../mk/bsd.options.mk"

PLIST_VARS+=		esd opengl x11

.if !empty(PKG_OPTIONS:Mcups)
.include "../../print/cups/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-cups
.endif

.if !empty(PKG_OPTIONS:Mdbus)
.include "../../sysutils/dbus/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-dbus
.endif

.if !empty(PKG_OPTIONS:Mesound)
PLIST.esd=		yes
.include "../../audio/esound/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mhal)
.include "../../sysutils/hal/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-hal
.endif

.if !empty(PKG_OPTIONS:Mldap)
.include "../../databases/openldap-client/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-ldap
.endif

.if !empty(PKG_OPTIONS:Mssl)
.include "../../security/openssl/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-openssl
.endif

.if !empty(PKG_OPTIONS:Mx11)
PLIST.x11=		yes
.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../x11/libICE/buildlink3.mk"
.include "../../x11/libSM/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXcomposite/buildlink3.mk"
.include "../../x11/libXcursor/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXi/buildlink3.mk"
.include "../../x11/libXinerama/buildlink3.mk"
.include "../../x11/libXrandr/buildlink3.mk"
.include "../../x11/libXrender/buildlink3.mk"
.include "../../x11/libXxf86vm/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-freetype
CONFIGURE_ARGS+=	--without-x
.endif

.if !empty(PKG_OPTIONS:Mopengl) && !empty(PKG_OPTIONS:Mx11)
PLIST.opengl=		yes
.include "../../graphics/glu/buildlink3.mk"
.include "../../graphics/glut/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-opengl
.endif

.if !empty(PKG_OPTIONS:Msane)
.include "../../graphics/sane-backends/buildlink3.mk"
.endif
