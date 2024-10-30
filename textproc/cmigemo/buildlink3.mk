# $NetBSD: buildlink3.mk,v 1.1 2024/10/30 10:04:10 pho Exp $

BUILDLINK_TREE+=	cmigemo

.if !defined(CMIGEMO_BUILDLINK3_MK)
CMIGEMO_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.cmigemo+=	cmigemo>=1.3e.20110227nb11
BUILDLINK_PKGSRCDIR.cmigemo?=	../../textproc/cmigemo
.endif	# CMIGEMO_BUILDLINK3_MK

BUILDLINK_TREE+=	-cmigemo
