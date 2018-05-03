# $NetBSD: buildlink3.mk,v 1.2 2018/05/03 13:13:51 schmonz Exp $

BUILDLINK_TREE+=	libhighlight

.if !defined(LIBHIGHLIGHT_BUILDLINK3_MK)
LIBHIGHLIGHT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libhighlight+=	libhighlight>=3.42
BUILDLINK_PKGSRCDIR.libhighlight?=	../../textproc/libhighlight
.endif	# LIBHIGHLIGHT_BUILDLINK3_MK

BUILDLINK_TREE+=	-libhighlight
