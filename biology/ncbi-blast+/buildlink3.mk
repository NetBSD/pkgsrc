# $NetBSD: buildlink3.mk,v 1.6 2023/05/28 22:48:27 bacon Exp $

BUILDLINK_TREE+=	ncbi-blast+

.if !defined(NCBI_BLAST+_BUILDLINK3_MK)
NCBI_BLAST+_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ncbi-blast++=	ncbi-blast+>=2.14.0
BUILDLINK_PKGSRCDIR.ncbi-blast+?=	../../biology/ncbi-blast+

.endif	# NCBI_BLAST+_BUILDLINK3_MK

BUILDLINK_TREE+=	-ncbi-blast+
