# $NetBSD: buildlink3.mk,v 1.3 2021/06/11 13:47:40 bacon Exp $

BUILDLINK_TREE+=	ncbi-blast+

.if !defined(NCBI_BLAST+_BUILDLINK3_MK)
NCBI_BLAST+_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ncbi-blast++=	ncbi-blast+>=2.11.0
BUILDLINK_PKGSRCDIR.ncbi-blast+?=	../../biology/ncbi-blast+

.endif	# NCBI_BLAST+_BUILDLINK3_MK

BUILDLINK_TREE+=	-ncbi-blast+
