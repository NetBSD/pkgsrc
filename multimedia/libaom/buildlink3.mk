# $NetBSD: buildlink3.mk,v 1.2 2021/10/09 15:35:09 nia Exp $

BUILDLINK_TREE+=	libaom

.if !defined(LIBAOM_BUILDLINK3_MK)
LIBAOM_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libaom+=	libaom>=1.0.0
BUILDLINK_ABI_DEPENDS.libaom?=	libaom>=3.1.3nb1
BUILDLINK_PKGSRCDIR.libaom?=	../../multimedia/libaom
.endif	# LIBAOM_BUILDLINK3_MK

BUILDLINK_TREE+=	-libaom
