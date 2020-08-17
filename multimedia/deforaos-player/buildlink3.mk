# $NetBSD: buildlink3.mk,v 1.16 2020/08/17 20:17:37 leot Exp $
#

BUILDLINK_TREE+=	deforaos-player

.if !defined(DEFORAOS_PLAYER_BUILDLINK3_MK)
DEFORAOS_PLAYER_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.deforaos-player+=	deforaos-player>=0.1.6
BUILDLINK_ABI_DEPENDS.deforaos-player?=	deforaos-player>=0.2.0nb3
BUILDLINK_PKGSRCDIR.deforaos-player?=	../../multimedia/deforaos-player

.include "../../x11/deforaos-libdesktop/buildlink3.mk"
.endif	# DEFORAOS_PLAYER_BUILDLINK3_MK

BUILDLINK_TREE+=	-deforaos-player
