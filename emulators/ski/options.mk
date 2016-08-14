# $NetBSD: options.mk,v 1.1 2016/08/14 18:27:05 scole Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.ski
PKG_SUPPORTED_OPTIONS=	debug gtk motif
PKG_SUGGESTED_OPTIONS=	gtk motif

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mdebug)
CPPFLAGS+=		-g
INSTALL_UNSTRIPPED=	yes
.endif

PLIST_VARS+=		xski
.if !empty(PKG_OPTIONS:Mmotif)
PLIST.xski=		yes
CONFIGURE_ARGS+=	--with-x11
INSTALLATION_DIRS+=	lib/X11/app-defaults

.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../x11/libxcb/buildlink3.mk"
.include "../../x11/motif/buildlink3.mk"
.endif

PLIST_VARS+=		gski
.if !empty(PKG_OPTIONS:Mgtk)
PLIST.gski=		yes
CONFIGURE_ARGS+=	--with-gtk

.include "../../devel/libglade/buildlink3.mk"
.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../x11/libxcb/buildlink3.mk"
.endif
