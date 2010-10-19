# $NetBSD: buildlink3.mk,v 1.1.1.1 2010/10/19 16:37:40 abs Exp $

BUILDLINK_TREE+=	mlt

.if !defined(MLT_BUILDLINK3_MK)
MLT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.mlt+=	mlt>=0.5.10
BUILDLINK_ABI_DEPENDS.mlt+=	mlt>=0.5.10
BUILDLINK_PKGSRCDIR.mlt?=	../../multimedia/mlt
.endif # MLT_BUILDLINK3_MK

BUILDLINK_TREE+=	-mlt
