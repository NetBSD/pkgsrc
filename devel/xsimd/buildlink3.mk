# $NetBSD: buildlink3.mk,v 1.1 2026/09/06 09:25:21 markd Exp $

BUILDLINK_TREE+=	xsimd

.if !defined(XSIMD_BUILDLINK3_MK)
XSIMD_BUILDLINK3_MK:=

BUILDLINK_DEPMETHOD.xsimd?=	build

BUILDLINK_API_DEPENDS.xsimd+=	xsimd>=14.3.0
BUILDLINK_PKGSRCDIR.xsimd?=	../../devel/xsimd
.endif	# XSIMD_BUILDLINK3_MK

BUILDLINK_TREE+=	-xsimd
