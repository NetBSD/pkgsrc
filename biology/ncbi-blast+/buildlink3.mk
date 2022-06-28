# $NetBSD: buildlink3.mk,v 1.5 2022/06/28 11:31:01 wiz Exp $

BUILDLINK_TREE+=	ncbi-blast+

.if !defined(NCBI_BLAST+_BUILDLINK3_MK)
NCBI_BLAST+_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ncbi-blast++=	ncbi-blast+>=2.13.0
BUILDLINK_ABI_DEPENDS.ncbi-blast+?=	ncbi-blast+>=2.13.0nb2
BUILDLINK_PKGSRCDIR.ncbi-blast+?=	../../biology/ncbi-blast+

.endif	# NCBI_BLAST+_BUILDLINK3_MK

BUILDLINK_TREE+=	-ncbi-blast+
