# $NetBSD: options.mk,v 1.4 2016/02/04 11:50:24 leot Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.mupdf
PKG_SUPPORTED_OPTIONS=	curl glfw

.include "../../mk/bsd.options.mk"

PLIST_VARS+=		glfw

#
# curl support
#
.if !empty(PKG_OPTIONS:Mcurl)
.include "../../www/curl/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.endif

#
# glfw support
#
.if !empty(PKG_OPTIONS:Mglfw)
PLIST.glfw=	yes
.include "../../graphics/glut/buildlink3.mk"
.include "../../graphics/glfw/buildlink3.mk"
.endif
