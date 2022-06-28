# $NetBSD: buildlink3.mk,v 1.4 2022/06/28 11:34:56 wiz Exp $

BUILDLINK_TREE+=	libaom

.if !defined(LIBAOM_BUILDLINK3_MK)
LIBAOM_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libaom+=	libaom>=1.0.0
BUILDLINK_ABI_DEPENDS.libaom?=	libaom>=3.3.0nb1
BUILDLINK_PKGSRCDIR.libaom?=	../../multimedia/libaom
.endif	# LIBAOM_BUILDLINK3_MK

BUILDLINK_TREE+=	-libaom
