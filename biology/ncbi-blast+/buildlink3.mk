# $NetBSD: buildlink3.mk,v 1.9 2023/09/14 00:39:17 bacon Exp $

BUILDLINK_TREE+=	ncbi-blast+

.if !defined(NCBI_BLAST+_BUILDLINK3_MK)
NCBI_BLAST+_BUILDLINK3_MK:=

USE_CXX_FEATURES=			c++17

BUILDLINK_API_DEPENDS.ncbi-blast++=	ncbi-blast+>=2.14.1
BUILDLINK_ABI_DEPENDS.ncbi-blast++=	ncbi-blast+>=2.14.1
BUILDLINK_PKGSRCDIR.ncbi-blast+?=	../../biology/ncbi-blast+

.endif	# NCBI_BLAST+_BUILDLINK3_MK

BUILDLINK_TREE+=	-ncbi-blast+
