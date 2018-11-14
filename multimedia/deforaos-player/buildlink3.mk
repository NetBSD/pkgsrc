# $NetBSD: buildlink3.mk,v 1.12 2018/11/14 22:22:04 kleink Exp $
#

BUILDLINK_TREE+=	deforaos-player

.if !defined(DEFORAOS_PLAYER_BUILDLINK3_MK)
DEFORAOS_PLAYER_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.deforaos-player+=	deforaos-player>=0.1.6
BUILDLINK_ABI_DEPENDS.deforaos-player?=	deforaos-player>=0.1.6nb11
BUILDLINK_PKGSRCDIR.deforaos-player?=	../../multimedia/deforaos-player

.include "../../x11/deforaos-libdesktop/buildlink3.mk"
.endif	# DEFORAOS_PLAYER_BUILDLINK3_MK

BUILDLINK_TREE+=	-deforaos-player
