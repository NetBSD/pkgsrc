# $NetBSD: buildlink3.mk,v 1.6 2024/07/06 15:45:08 adam Exp $

BUILDLINK_TREE+=	openmp

.if !defined(OPENMP_BUILDLINK3_MK)
OPENMP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.openmp+=	openmp>=18.0.0
BUILDLINK_ABI_DEPENDS.openmp+=	openmp>=18.0.0
BUILDLINK_PKGSRCDIR.openmp?=	../../parallel/openmp
.endif	# OPENMP_BUILDLINK3_MK

BUILDLINK_TREE+=	-openmp
