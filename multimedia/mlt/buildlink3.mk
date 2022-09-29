# $NetBSD: buildlink3.mk,v 1.3 2022/09/29 00:06:48 markd Exp $

BUILDLINK_TREE+=	mlt

.if !defined(MLT_BUILDLINK3_MK)
MLT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.mlt+=	mlt>=7.8.0
BUILDLINK_ABI_DEPENDS.mlt+=	mlt>=7.8.0
BUILDLINK_PKGSRCDIR.mlt?=	../../multimedia/mlt
.endif # MLT_BUILDLINK3_MK

BUILDLINK_TREE+=	-mlt
