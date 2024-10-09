# $NetBSD: options.mk,v 1.1 2024/10/09 19:53:19 adam Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.python313
PKG_SUPPORTED_OPTIONS=	dtrace pymalloc tkinter x11 readline
PKG_SUGGESTED_OPTIONS=	x11 readline

.include "../../mk/bsd.prefs.mk"
.include "../../mk/bsd.options.mk"

PLIST_VARS+=		dtrace readline

.if !empty(PKG_OPTIONS:Mdtrace)
CONFIGURE_ARGS+=	--with-dtrace
PLIST.dtrace=		yes
.endif

.if !empty(PKG_OPTIONS:Mtkinter)
PLIST.tkinter=	yes
.include "../../lang/tcl/buildlink3.mk"
.include "../../x11/tk/buildlink3.mk"
.else
CONFIGURE_ENV+=		py_cv_module__tkinter="n/a"
.endif

.if !empty(PKG_OPTIONS:Mx11)
# Support for native X11 paths as an option
# This code is no-op for modular X11, however for simplicity don't make it conditional.
SUBST_CLASSES+=		xfindlib
SUBST_MESSAGE.xfindlib=	Fixing find_library() for native X11.
SUBST_STAGE.xfindlib=	pre-configure
SUBST_FILES.xfindlib=	Lib/ctypes/util.py
SUBST_SED.xfindlib=	-e "s!\('-Wl,-t'\)!'${COMPILER_RPATH_FLAG}${X11BASE}/lib', '-L${X11BASE}/lib', \1!"

# Required to get definition of X11BASE and retain X11 rpath paths for linker
# We need to pass rpath to _ctypes.so to get functional dlopen(3) for X11 libs
USE_X11=	weak
.endif

.if !empty(PKG_OPTIONS:Mpymalloc)
CONFIGURE_ARGS+=	--with-pymalloc
.else
CONFIGURE_ARGS+=	--without-pymalloc
.endif

.if ${PKG_OPTIONS:Mreadline}
.  include "../../mk/readline.buildlink3.mk"
CONFIGURE_ARGS+=	--with-readline=readline
PLIST.readline=		yes
.else
CONFIGURE_ARGS+=	--without-readline
.endif
