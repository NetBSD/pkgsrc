# $NetBSD: buildlink3.mk,v 1.6 2021/12/17 15:01:27 bacon Exp $

BUILDLINK_TREE+=	htslib

.if !defined(HTSLIB_BUILDLINK3_MK)
HTSLIB_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.htslib+=	htslib>=1.14
BUILDLINK_ABI_DEPENDS.htslib+=	htslib>=1.14
BUILDLINK_PKGSRCDIR.htslib?=	../../biology/htslib

.endif	# HTSLIB_BUILDLINK3_MK

BUILDLINK_TREE+=	-htslib
