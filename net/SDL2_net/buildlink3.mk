# $NetBSD: buildlink3.mk,v 1.4 2020/08/18 17:57:30 leot Exp $

BUILDLINK_TREE+=	SDL2_net

.if !defined(SDL2_NET_BUILDLINK3_MK)
SDL2_NET_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.SDL2_net+=	SDL2_net>=2.0.0nb2
BUILDLINK_ABI_DEPENDS.SDL2_net?=		SDL2_net>=2.0.1nb2
BUILDLINK_PKGSRCDIR.SDL2_net?=		../../net/SDL2_net

.include "../../devel/SDL2/buildlink3.mk"
.endif	# SDL2_NET_BUILDLINK3_MK

BUILDLINK_TREE+=	-SDL2_net
