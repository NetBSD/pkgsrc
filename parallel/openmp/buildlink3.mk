# $NetBSD: buildlink3.mk,v 1.7 2025/05/09 05:51:26 adam Exp $

BUILDLINK_TREE+=	openmp

.if !defined(OPENMP_BUILDLINK3_MK)
OPENMP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.openmp+=	openmp>=19.1.0
BUILDLINK_ABI_DEPENDS.openmp+=	openmp>=19.1.0
BUILDLINK_PKGSRCDIR.openmp?=	../../parallel/openmp
.endif	# OPENMP_BUILDLINK3_MK

BUILDLINK_TREE+=	-openmp
