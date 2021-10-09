# $NetBSD: buildlink3.mk,v 1.3 2021/10/09 20:36:04 ryoon Exp $

BUILDLINK_TREE+=	libaom

.if !defined(LIBAOM_BUILDLINK3_MK)
LIBAOM_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libaom+=	libaom>=1.0.0
BUILDLINK_ABI_DEPENDS.libaom?=	libaom>=3.1.3
BUILDLINK_PKGSRCDIR.libaom?=	../../multimedia/libaom
.endif	# LIBAOM_BUILDLINK3_MK

BUILDLINK_TREE+=	-libaom
