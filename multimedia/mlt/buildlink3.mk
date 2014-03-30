# $NetBSD: buildlink3.mk,v 1.2 2014/03/30 19:42:53 abs Exp $

BUILDLINK_TREE+=	mlt

.if !defined(MLT_BUILDLINK3_MK)
MLT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.mlt+=	mlt>=0.9.0
BUILDLINK_ABI_DEPENDS.mlt+=	mlt>=0.9.0
BUILDLINK_PKGSRCDIR.mlt?=	../../multimedia/mlt
.endif # MLT_BUILDLINK3_MK

BUILDLINK_TREE+=	-mlt
