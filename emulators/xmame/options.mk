# $NetBSD: options.mk,v 1.1 2004/11/08 10:03:41 xtraeme Exp $
#

PKG_OPTIONS_VAR=	PKG_OPTIONS.xmame
PKG_SUPPORTED_OPTIONS=	sdl opengl esound
.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Msdl)
MAME_DISP_METHOD?=	SDL
.include "../../devel/SDL/buildlink3.mk"
.elif !empty(PKG_OPTIONS:Mopengl)
MAME_DISP_METHOD?=	xgl
.include "../../graphics/Mesa/buildlink3.mk"
.else
MAME_DISP_METHOD?=	x11
.endif

.if !empty(PKG_OPTIONS:Msdl) && !empty(PKG_OPTIONS:Mopengl)
PKG_SKIP_REASON+=	"Only one display method is allowed."
.endif

.if !empty(PKG_OPTIONS:Mesound)
MAKE_FLAGS+=		SOUND_ESOUND=1
.inclUde "../../audio/esound/buildlink3.mk"
.endif
