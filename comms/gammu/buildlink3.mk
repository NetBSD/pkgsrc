# $NetBSD: buildlink3.mk,v 1.2 2015/08/17 16:42:53 leot Exp $

BUILDLINK_TREE+=	gammu

.if !defined(GAMMU_BUILDLINK3_MK)
GAMMU_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gammu+=	gammu>=1.34.0
BUILDLINK_PKGSRCDIR.gammu?=	../../comms/gammu

.endif	# GAMMU_BUILDLINK3_MK

BUILDLINK_TREE+=	-gammu
