# $NetBSD: options.mk,v 1.7 2024/05/06 08:33:51 jperkin Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.libcaca
PKG_SUPPORTED_OPTIONS=		imlib2
PKG_OPTIONS_REQUIRED_GROUPS=	driver
PKG_OPTIONS_GROUP.driver=	ncurses slang x11
PKG_SUGGESTED_OPTIONS=		ncurses

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mimlib2)
.  include "../../graphics/imlib2/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-imlib2
.else
CONFIGURE_ARGS+=	--disable-imlib2
.endif

.if !empty(PKG_OPTIONS:Mncurses)
.  include "../../devel/ncurses/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-ncurses
.else
CONFIGURE_ARGS+=	--disable-ncurses
.endif

.if !empty(PKG_OPTIONS:Mslang)
.  include "../../devel/libslang/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-slang
.else
CONFIGURE_ARGS+=	--disable-slang
.endif

.if !empty(PKG_OPTIONS:Mx11)
.  include "../../x11/libXt/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-x11
.  if ${X11_TYPE} == "modular"
CONFIGURE_ARGS+=	--x-libraries=${BUILDLINK_PREFIX.libX11}/lib
.  endif
.else
CONFIGURE_ARGS+=	--disable-x11
.endif

# could be made into options if desired
.for i in gl cocoa network vga csharp java cxx python ruby cppunit zzuf
CONFIGURE_ARGS+=	--disable-${i}
.endfor
