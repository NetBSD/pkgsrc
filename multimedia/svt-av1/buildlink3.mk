# $NetBSD: buildlink3.mk,v 1.1 2023/04/09 11:13:51 plunky Exp $

BUILDLINK_TREE+=	svt-av1

.if !defined(SVT_AV1_BUILDLINK3_MK)
SVT_AV1_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.svt-av1+=	svt-av1>=1.4.1
BUILDLINK_PKGSRCDIR.svt-av1?=	../../multimedia/svt-av1

.endif	# SVT_AV1_BUILDLINK3_MK

BUILDLINK_TREE+=	-svt-av1
