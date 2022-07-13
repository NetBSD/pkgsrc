# $NetBSD: buildlink3.mk,v 1.5 2022/07/13 00:52:30 schmonz Exp $

BUILDLINK_TREE+=	libhighlight

.if !defined(LIBHIGHLIGHT_BUILDLINK3_MK)
LIBHIGHLIGHT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libhighlight+=	libhighlight>=4.2
BUILDLINK_PKGSRCDIR.libhighlight?=	../../textproc/libhighlight
.endif	# LIBHIGHLIGHT_BUILDLINK3_MK

BUILDLINK_TREE+=	-libhighlight
