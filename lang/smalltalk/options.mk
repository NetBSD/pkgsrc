# $NetBSD: options.mk,v 1.1.2.1 2015/02/05 19:40:14 tron Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.smalltalk
PKG_SUPPORTED_OPTIONS=	cairo curses expat gdbm gtk opengl readline sdl sqlite tk
PKG_SUGGESTED_OPTIONS=	cairo curses expat gdbm gtk opengl readline tk

PLIST_VARS+=		${PKG_SUPPORTED_OPTIONS}
PLIST_VARS+=		blox

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mcairo)
PLIST.cairo=		yes
.  include "../../graphics/cairo/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-cairo
.endif

.if !empty(PKG_OPTIONS:Mcurses)
PLIST.curses=		yes
# it only searches for ncurses but seems to be ok with at least netbsd's curses
FAKE_NCURSES=		yes
.include "../../mk/curses.buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-ncurses
.endif

.if !empty(PKG_OPTIONS:Mexpat)
PLIST.expat=		yes
.include "../../textproc/expat/buildlink3.mk"
.else
CONFIGURE_ENV+=		ac_cv_header_expat_h=no
.endif

# XXX: there are mysql, postgres modules too
.if !empty(PKG_OPTIONS:Mgdbm)
PLIST.gdbm=		yes
CONFIGURE_ARGS+=	--with-gdbm=${BUILDLINK_PREFIX.gdbm}/lib
.  include "../../databases/gdbm/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-gdbm
.endif

.if !empty(PKG_OPTIONS:Mgtk)
PLIST.gtk=		yes
PLIST.blox=		yes
.  include "../../devel/atk/buildlink3.mk"
.  include "../../devel/glib2/buildlink3.mk"
.  include "../../devel/pango/buildlink3.mk"
.  include "../../x11/gtk2/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-glib --without-gtk
.endif

.if !empty(PKG_OPTIONS:Mopengl)
PLIST.opengl=		yes
.  include "../../graphics/MesaLib/buildlink3.mk"
.  include "../../graphics/glu/buildlink3.mk"
.  include "../../graphics/glut/buildlink3.mk"
.  include "../../x11/libICE/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-opengl
CONFIGURE_ARGS+=	--disable-glut
.endif

.if !empty(PKG_OPTIONS:Mreadline)
PLIST.readline=		yes
CONFIGURE_ARGS+=	--with-readline=${BUILDLINK_PREFIX.readline}/lib
.  include "../../devel/readline/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-readline
.endif

.if !empty(PKG_OPTIONS:Msdl)
PLIST.sdl=		yes
.  include "../../devel/SDL/buildlink3.mk"
.  include "../../graphics/SDL_image/buildlink3.mk"
.  include "../../audio/SDL_mixer/buildlink3.mk"
.  include "../../audio/SDL_sound/buildlink3.mk"
.  include "../../devel/SDL_ttf/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-SDL
.endif

.if !empty(PKG_OPTIONS:Msqlite)
PLIST.sqlite=		yes
.  include "../../databases/sqlite3/buildlink3.mk"
.else
CONFIGURE_ENV+=		ac_cv_header_sqlite3_h=no
.endif

.if !empty(PKG_OPTIONS:Mtk)
PLIST.tk=		yes
PLIST.blox=		yes
CONFIGURE_ARGS+=	--with-tcl=${BUILDLINK_PREFIX.tcl}/lib
CONFIGURE_ARGS+=	--with-tk=${BUILDLINK_PREFIX.tk}/lib
.  include "../../lang/tcl/buildlink3.mk"
.  include "../../x11/tk/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-tcl
CONFIGURE_ARGS+=	--without-tk
.endif
