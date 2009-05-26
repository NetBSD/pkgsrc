# $NetBSD: buildlink3.mk,v 1.1 2009/05/26 21:31:21 wiz Exp $

BUILDLINK_TREE+=	gammu

.if !defined(GAMMU_BUILDLINK3_MK)
GAMMU_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gammu+=	gammu>=1.24.0
BUILDLINK_PKGSRCDIR.gammu?=	../../comms/gammu

.endif	# GAMMU_BUILDLINK3_MK

BUILDLINK_TREE+=	-gammu
