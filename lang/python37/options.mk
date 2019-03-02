# $NetBSD: options.mk,v 1.3 2019/03/02 13:23:36 adam Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.python37
PKG_SUPPORTED_OPTIONS=	dtrace pymalloc x11
PKG_SUGGESTED_OPTIONS=	x11

.include "../../mk/bsd.prefs.mk"
.include "../../mk/bsd.options.mk"

PLIST_VARS+=		dtrace pymalloc

.if !empty(PKG_OPTIONS:Mdtrace)
CONFIGURE_ARGS+=	--with-dtrace
PLIST.dtrace=		yes
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
USE_X11=		yes

SUBST_CLASSES+=		cdlopen
SUBST_MESSAGE.cdlopen=	Handle X11BASE paths in dlopen(3) calls of _ctypes.so
SUBST_STAGE.cdlopen=	pre-configure
SUBST_FILES.cdlopen=	setup.py
SUBST_SED.cdlopen=	-e "s!\(libraries=\[\],\)!\1 runtime_library_dirs=\['${X11BASE}/lib'\],!"
.endif

.if !empty(PKG_OPTIONS:Mpymalloc)
PLIST_SUBST+=		M=m
PLIST.pymalloc=		yes
PRINT_PLIST_AWK+=	{ gsub(/PY_VER_SUFFIX}m/, "PY_VER_SUFFIX}$${M}") }
PRINT_PLIST_AWK+=	{ gsub(/config-${PY_VER_SUFFIX}m/, "config-$${PY_VER_SUFFIX}$${M}") }
.else
CONFIGURE_ARGS+=	--without-pymalloc
PLIST_SUBST+=		M=
.endif
