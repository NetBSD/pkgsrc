# $NetBSD: options.mk,v 1.3 2020/01/21 10:57:26 kamil Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.python27
PKG_SUPPORTED_OPTIONS+=	x11
PKG_SUGGESTED_OPTIONS=	x11

.include "../../mk/bsd.prefs.mk"
.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mx11)
# Support for native X11 paths as an option
# This code is no-op for modular X11, however for simplicity don't make it conditional.
SUBST_CLASSES+=		xfindlib
SUBST_MESSAGE.xfindlib=	Fixing find_library() for native X11.
SUBST_STAGE.xfindlib=	pre-configure
SUBST_FILES.xfindlib=	Lib/ctypes/util.py
SUBST_SED.xfindlib=	-e 's!\(-Wl,-t -o\)!${COMPILER_RPATH_FLAG}${X11BASE}/lib -L${X11BASE}/lib \1!'

# Required to get definition of X11BASE and retain X11 rpath paths for linker
# We need to pass rpath to _ctypes.so to get functional dlopen(3) for X11 libs
USE_X11=		weak

SUBST_CLASSES+=		cdlopen
SUBST_MESSAGE.cdlopen=	Handle X11BASE paths in dlopen(3) calls of _ctypes.so
SUBST_STAGE.cdlopen=	pre-configure
SUBST_FILES.cdlopen=	setup.py
SUBST_SED.cdlopen=	-e "s!\(libraries=\[\],\)!\1 runtime_library_dirs=\['${X11BASE}/lib'\],!"
.endif
