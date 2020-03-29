# $NetBSD: options.mk,v 1.2 2020/03/29 01:03:22 joerg Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.eureka
PKG_SUPPORTED_OPTIONS=	opengl xdg-utils
PKG_SUGGESTED_OPTIONS=	opengl xdg-utils

.include "../../mk/bsd.options.mk"

.include "../../x11/fltk13/buildlink3.mk"

# opengl: Use OpenGL for rendering
# If FLTK is compiled without opengl option, it is always disabled here too.
# If FLTK is compiled with opengl option, disabling it here allows to force
# usage of the software renderer (recommended without hardware acceleration).
.if empty(PKG_OPTIONS.fltk13:Mopengl) || empty(PKG_OPTIONS:Mopengl)
SUBST_CLASSES+=		opengl
SUBST_STAGE.opengl=	do-configure
SUBST_MESSAGE.opengl=	Disable OpenGL renderer in Makefile ...
SUBST_FILES.opengl=	Makefile
SUBST_SED.opengl=	-e 's,\# CXXFLAGS += -DNO_OPENGL,CXXFLAGS += -DNO_OPENGL,'
SUBST_SED.opengl+=	-e 's, --use-gl,,'
SUBST_SED.opengl+=	-e 's,LIBS += -lGLU -lGL,\#LIBS += -lGLU -lGL,'
.endif

# xdg-utils: Create dependency for xdg-utils (Portland project)
# Can be used by FLTK for fl_open_uri() on X11.
.if !empty(PKG_OPTIONS:Mxdg-utils)
DEPENDS+=	xdg-utils>=1.1:../../misc/xdg-utils
.endif

.if !empty(PKG_OPTIONS:Mopengl)
.include "../../x11/libXcursor/buildlink3.mk"
.endif
