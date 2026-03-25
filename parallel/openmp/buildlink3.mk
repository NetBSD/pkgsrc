# $NetBSD: buildlink3.mk,v 1.8 2026/03/25 23:06:03 wiz Exp $

BUILDLINK_TREE+=	openmp

.if !defined(OPENMP_BUILDLINK3_MK)
OPENMP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.openmp+=	openmp>=20.1.0
BUILDLINK_ABI_DEPENDS.openmp+=	openmp>=20.1.0
BUILDLINK_PKGSRCDIR.openmp?=	../../parallel/openmp
.endif	# OPENMP_BUILDLINK3_MK

BUILDLINK_TREE+=	-openmp
