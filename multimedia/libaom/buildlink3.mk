# $NetBSD: buildlink3.mk,v 1.5 2022/07/07 10:13:56 adam Exp $

BUILDLINK_TREE+=	libaom

.if !defined(LIBAOM_BUILDLINK3_MK)
LIBAOM_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libaom+=	libaom>=1.0.0
BUILDLINK_ABI_DEPENDS.libaom+=	libaom>=3.3.0nb1
BUILDLINK_PKGSRCDIR.libaom?=	../../multimedia/libaom
.endif	# LIBAOM_BUILDLINK3_MK

BUILDLINK_TREE+=	-libaom
