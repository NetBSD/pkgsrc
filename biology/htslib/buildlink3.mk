# $NetBSD: buildlink3.mk,v 1.8 2022/06/28 11:31:00 wiz Exp $

BUILDLINK_TREE+=	htslib

.if !defined(HTSLIB_BUILDLINK3_MK)
HTSLIB_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.htslib+=	htslib>=1.14
BUILDLINK_ABI_DEPENDS.htslib+=	htslib>=1.15nb1
BUILDLINK_PKGSRCDIR.htslib?=	../../biology/htslib

.endif	# HTSLIB_BUILDLINK3_MK

BUILDLINK_TREE+=	-htslib
