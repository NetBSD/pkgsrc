# $NetBSD: buildlink3.mk,v 1.3 2016/02/07 15:29:34 leot Exp $

BUILDLINK_TREE+=	gammu

.if !defined(GAMMU_BUILDLINK3_MK)
GAMMU_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gammu+=	gammu>=1.37.0
BUILDLINK_PKGSRCDIR.gammu?=	../../comms/gammu

.endif	# GAMMU_BUILDLINK3_MK

BUILDLINK_TREE+=	-gammu
