# $NetBSD: buildlink3.mk,v 1.8 2009/03/20 19:25:28 joerg Exp $

BUILDLINK_TREE+=	aiksaurus

.if !defined(AIKSAURUS_BUILDLINK3_MK)
AIKSAURUS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.aiksaurus+=	aiksaurus>=1.2.1
BUILDLINK_PKGSRCDIR.aiksaurus?=	../../textproc/aiksaurus
.endif # AIKSAURUS_BUILDLINK3_MK

BUILDLINK_TREE+=	-aiksaurus
