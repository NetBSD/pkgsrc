# $NetBSD: buildlink3.mk,v 1.12 2015/04/25 14:23:42 tnn Exp $

BUILDLINK_TREE+=	SDL_net

.if !defined(SDL_NET_BUILDLINK3_MK)
SDL_NET_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.SDL_net+=	SDL_net>=1.2.5nb1
BUILDLINK_ABI_DEPENDS.SDL_net+=	SDL_net>=1.2.8nb1
BUILDLINK_PKGSRCDIR.SDL_net?=	../../net/SDL_net

.include "../../devel/SDL/buildlink3.mk"
.endif # SDL_NET_BUILDLINK3_MK

BUILDLINK_TREE+=	-SDL_net
