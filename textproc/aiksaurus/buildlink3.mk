# $NetBSD: buildlink3.mk,v 1.9 2018/01/07 13:04:32 rillig Exp $

BUILDLINK_TREE+=	aiksaurus

.if !defined(AIKSAURUS_BUILDLINK3_MK)
AIKSAURUS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.aiksaurus+=	aiksaurus>=1.2.1
BUILDLINK_PKGSRCDIR.aiksaurus?=		../../textproc/aiksaurus
.endif # AIKSAURUS_BUILDLINK3_MK

BUILDLINK_TREE+=	-aiksaurus
