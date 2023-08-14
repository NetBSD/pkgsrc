# $NetBSD: buildlink3.mk,v 1.8 2023/08/14 05:23:51 wiz Exp $

BUILDLINK_TREE+=	ncbi-blast+

.if !defined(NCBI_BLAST+_BUILDLINK3_MK)
NCBI_BLAST+_BUILDLINK3_MK:=

USE_CXX_FEATURES+=			c++17

BUILDLINK_API_DEPENDS.ncbi-blast++=	ncbi-blast+>=2.14.0
BUILDLINK_ABI_DEPENDS.ncbi-blast+?=	ncbi-blast+>=2.14.0nb1
BUILDLINK_PKGSRCDIR.ncbi-blast+?=	../../biology/ncbi-blast+

.endif	# NCBI_BLAST+_BUILDLINK3_MK

BUILDLINK_TREE+=	-ncbi-blast+
