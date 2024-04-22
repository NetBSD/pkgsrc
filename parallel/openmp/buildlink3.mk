# $NetBSD: buildlink3.mk,v 1.5 2024/04/22 07:25:56 adam Exp $

BUILDLINK_TREE+=	openmp

.if !defined(OPENMP_BUILDLINK3_MK)
OPENMP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.openmp+=	openmp>=17.0.0<18
BUILDLINK_ABI_DEPENDS.openmp+=	openmp>=17.0.0
BUILDLINK_PKGSRCDIR.openmp?=	../../parallel/openmp
.endif	# OPENMP_BUILDLINK3_MK

BUILDLINK_TREE+=	-openmp
