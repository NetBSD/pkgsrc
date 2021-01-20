# $NetBSD: buildlink3.mk,v 1.1 2021/01/20 11:37:22 nia Exp $

BUILDLINK_TREE+=	libdivsufsort

.if !defined(LIBDIVSUFSORT_BUILDLINK3_MK)
LIBDIVSUFSORT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libdivsufsort+=	libdivsufsort>=2.0.1
BUILDLINK_PKGSRCDIR.libdivsufsort?=	../../devel/libdivsufsort
.endif	# LIBDIVSUFSORT_BUILDLINK3_MK

BUILDLINK_TREE+=	-libdivsufsort
