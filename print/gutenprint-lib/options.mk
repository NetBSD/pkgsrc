# $NetBSD: options.mk,v 1.2 2025/03/12 22:46:21 gdt Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.gutenprint
PKG_SUPPORTED_OPTIONS=	gimp
PKG_SUGGESTED_OPTIONS=

.include "../../mk/bsd.options.mk"

PLIST_VARS+=		gimp

###
### Gimp support
###
.if !empty(PKG_OPTIONS:Mgimp)
CONFIGURE_ARGS+=	--with-gimp2
CONFIGURE_ARGS+=	--with-gimp2-as-gutenprint
PLIST.gimp=		yes
.  include "../../graphics/gimp/buildlink3.mk"
.  include "../../x11/gtk2/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-gimp2
.endif
