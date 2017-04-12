# $NetBSD: options.mk,v 1.5 2017/04/12 13:03:08 leot Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.mupdf
PKG_SUPPORTED_OPTIONS=	curl glfw

.include "../../mk/bsd.options.mk"

PLIST_VARS+=		glfw

#
# curl support
#
.if !empty(PKG_OPTIONS:Mcurl)
.include "../../www/curl/buildlink3.mk"
.endif

#
# glfw support
#
.if !empty(PKG_OPTIONS:Mglfw)
PLIST.glfw=	yes
.include "../../graphics/MesaLib/buildlink3.mk"
BUILDLINK_API_DEPENDS.glfw+=	glfw>=3.2.1
.include "../../graphics/glfw/buildlink3.mk"
.endif
