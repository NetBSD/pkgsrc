# $NetBSD: buildlink3.mk,v 1.26 2018/11/12 03:51:09 ryoon Exp $

BUILDLINK_TREE+=	SDL_Pango

.if !defined(SDL_PANGO_BUILDLINK3_MK)
SDL_PANGO_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.SDL_Pango+=	SDL_Pango>=0.1.2
BUILDLINK_ABI_DEPENDS.SDL_Pango+=	SDL_Pango>=0.1.2nb25
BUILDLINK_PKGSRCDIR.SDL_Pango?=		../../devel/SDL_Pango

# Seems to be unnecessary, pkg-config does not show anything from SDL
#.include "../../devel/SDL/buildlink3.mk"
.include "../../devel/pango/buildlink3.mk"
.endif # SDL_PANGO_BUILDLINK3_MK

BUILDLINK_TREE+=	-SDL_Pango
