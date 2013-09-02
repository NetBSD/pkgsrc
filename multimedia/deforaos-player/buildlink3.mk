# $NetBSD: buildlink3.mk,v 1.2 2013/09/02 19:50:49 adam Exp $
#

BUILDLINK_TREE+=	deforaos-player

.if !defined(DEFORAOS_PLAYER_BUILDLINK3_MK)
DEFORAOS_PLAYER_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.deforaos-player+=	deforaos-player>=0.1.6
BUILDLINK_ABI_DEPENDS.deforaos-player?=	deforaos-player>=0.1.6nb1
BUILDLINK_PKGSRCDIR.deforaos-player?=	../../multimedia/deforaos-player

.include "../../x11/deforaos-libdesktop/buildlink3.mk"
.endif	# DEFORAOS_PLAYER_BUILDLINK3_MK

BUILDLINK_TREE+=	-deforaos-player
