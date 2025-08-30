# $NetBSD: buildlink3.mk,v 1.3 2025/08/30 04:40:06 ryoon Exp $

BUILDLINK_TREE+=	svt-av1

.if !defined(SVT_AV1_BUILDLINK3_MK)
SVT_AV1_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.svt-av1+=	svt-av1>=3.0.0
BUILDLINK_PKGSRCDIR.svt-av1?=	../../multimedia/svt-av1

.endif	# SVT_AV1_BUILDLINK3_MK

BUILDLINK_TREE+=	-svt-av1
