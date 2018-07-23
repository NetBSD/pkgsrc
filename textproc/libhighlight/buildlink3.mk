# $NetBSD: buildlink3.mk,v 1.3 2018/07/23 05:16:43 schmonz Exp $

BUILDLINK_TREE+=	libhighlight

.if !defined(LIBHIGHLIGHT_BUILDLINK3_MK)
LIBHIGHLIGHT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libhighlight+=	libhighlight>=3.44
BUILDLINK_PKGSRCDIR.libhighlight?=	../../textproc/libhighlight
.endif	# LIBHIGHLIGHT_BUILDLINK3_MK

BUILDLINK_TREE+=	-libhighlight
