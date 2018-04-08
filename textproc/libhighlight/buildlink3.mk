# $NetBSD: buildlink3.mk,v 1.1 2018/04/08 19:40:29 schmonz Exp $

BUILDLINK_TREE+=	libhighlight

.if !defined(LIBHIGHLIGHT_BUILDLINK3_MK)
LIBHIGHLIGHT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libhighlight+=	libhighlight>=3.18
BUILDLINK_PKGSRCDIR.libhighlight?=	../../textproc/libhighlight
.endif	# LIBHIGHLIGHT_BUILDLINK3_MK

BUILDLINK_TREE+=	-libhighlight
