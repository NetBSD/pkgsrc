# $NetBSD: options.mk,v 1.13 2023/09/07 14:36:54 vins Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.mupdf
PKG_SUPPORTED_OPTIONS=	curl opengl

.include "../../mk/bsd.fast.prefs.mk"

.if ${OPSYS} != "Darwin"
PKG_SUGGESTED_OPTIONS=	opengl
.endif

.include "../../mk/bsd.options.mk"

PLIST_VARS+=		curl opengl

#
# curl support
#
.if !empty(PKG_OPTIONS:Mcurl)
PLIST.curl=	yes
.include "../../security/openssl/buildlink3.mk"	#-lcrypto
.include "../../www/curl/buildlink3.mk"
.endif

#
# glut support
#
.if !empty(PKG_OPTIONS:Mopengl)
PLIST.opengl=	yes
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../graphics/freeglut/buildlink3.mk"
LDFLAGS+=	-lGL # for glCallList
.else
MAKE_ENV+=	HAVE_GLUT=no
.endif
