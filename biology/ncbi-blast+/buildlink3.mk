# $NetBSD: buildlink3.mk,v 1.10 2025/01/16 01:06:31 bacon Exp $

BUILDLINK_TREE+=	ncbi-blast+

.if !defined(NCBI_BLAST+_BUILDLINK3_MK)
NCBI_BLAST+_BUILDLINK3_MK:=

USE_CXX_FEATURES=			c++17

BUILDLINK_API_DEPENDS.ncbi-blast++=	ncbi-blast+>=2.16.0
BUILDLINK_ABI_DEPENDS.ncbi-blast++=	ncbi-blast+>=2.16.0
BUILDLINK_PKGSRCDIR.ncbi-blast+?=	../../biology/ncbi-blast+

.endif	# NCBI_BLAST+_BUILDLINK3_MK

BUILDLINK_TREE+=	-ncbi-blast+
