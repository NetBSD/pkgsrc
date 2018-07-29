# $NetBSD: buildlink3.mk,v 1.1 2018/07/29 07:38:48 wiz Exp $

BUILDLINK_TREE+=	djbsort

.if !defined(DJBSORT_BUILDLINK3_MK)
DJBSORT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.djbsort+=	djbsort>=20180717
BUILDLINK_PKGSRCDIR.djbsort?=	../../math/djbsort
BUILDLINK_DEPMETHOD.djbsort?=	build
.endif	# DJBSORT_BUILDLINK3_MK

BUILDLINK_TREE+=	-djbsort
