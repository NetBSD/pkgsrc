# $NetBSD: buildlink3.mk,v 1.2 2024/08/21 17:00:41 wiz Exp $

BUILDLINK_TREE+=	svt-av1

.if !defined(SVT_AV1_BUILDLINK3_MK)
SVT_AV1_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.svt-av1+=	svt-av1>=1.4.1
BUILDLINK_ABI_DEPENDS.svt-av1?=	svt-av1>=2.1.0
BUILDLINK_PKGSRCDIR.svt-av1?=	../../multimedia/svt-av1

.endif	# SVT_AV1_BUILDLINK3_MK

BUILDLINK_TREE+=	-svt-av1
