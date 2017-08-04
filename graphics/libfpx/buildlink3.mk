# $NetBSD: buildlink3.mk,v 1.1 2017/08/04 08:24:24 nros Exp $

BUILDLINK_TREE+=	libfpx

.if !defined(LIBFPX_BUILDLINK3_MK)
LIBFPX_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libfpx+=	libfpx>=1.3.1
BUILDLINK_PKGSRCDIR.libfpx?=	../../graphics/libfpx
.endif	# LIBFPX_BUILDLINK3_MK

BUILDLINK_TREE+=	-libfpx
