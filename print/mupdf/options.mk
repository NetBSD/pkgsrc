# $NetBSD: options.mk,v 1.9 2019/08/30 17:01:34 nia Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.mupdf
PKG_SUPPORTED_OPTIONS=	curl opengl

.include "../../mk/bsd.options.mk"

PLIST_VARS+=		curl opengl

#
# curl support
#
.if !empty(PKG_OPTIONS:Mcurl)
PLIST.curl=	yes
.include "../../www/curl/buildlink3.mk"
.endif

#
# glut support
#
.if !empty(PKG_OPTIONS:Mopengl)
PLIST.opengl=	yes
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../graphics/freeglut/buildlink3.mk"
.else
MAKE_ENV+=	HAVE_GLUT=no
.endif
