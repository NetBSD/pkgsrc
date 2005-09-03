# $NetBSD: options.mk,v 1.3 2005/09/03 18:16:07 xtraeme Exp $
#

PKG_OPTIONS_VAR=		PKG_OPTIONS.xmame
PKG_OPTIONS_OPTIONAL_GROUPS=	video
PKG_OPTIONS_GROUP.video=	sdl opengl
PKG_SUPPORTED_OPTIONS=		esound

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

.if !empty(PKG_OPTIONS:Mesound)
MAKE_FLAGS+=		SOUND_ESOUND=1
.include "../../audio/esound/buildlink3.mk"
.endif
