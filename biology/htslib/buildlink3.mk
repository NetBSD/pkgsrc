# $NetBSD: buildlink3.mk,v 1.10 2024/10/11 22:36:15 bacon Exp $

BUILDLINK_TREE+=	htslib

.if !defined(HTSLIB_BUILDLINK3_MK)
HTSLIB_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.htslib+=	htslib>=1.21
BUILDLINK_ABI_DEPENDS.htslib+=	htslib>=1.21
BUILDLINK_PKGSRCDIR.htslib?=	../../biology/htslib

.endif	# HTSLIB_BUILDLINK3_MK

BUILDLINK_TREE+=	-htslib
