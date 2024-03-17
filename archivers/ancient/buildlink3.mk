# $NetBSD: buildlink3.mk,v 1.1 2024/03/17 16:42:28 nia Exp $

BUILDLINK_TREE+=	ancient

.if !defined(ANCIENT_BUILDLINK3_MK)
ANCIENT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ancient+=	ancient>=2.0.0
BUILDLINK_PKGSRCDIR.ancient?=	../../archivers/ancient
.endif	# ANCIENT_BUILDLINK3_MK

BUILDLINK_TREE+=	-ancient
