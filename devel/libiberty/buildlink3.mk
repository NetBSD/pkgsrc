# $NetBSD: buildlink3.mk,v 1.10 2018/01/07 13:04:06 rillig Exp $

BUILDLINK_TREE+=	libiberty

.if !defined(LIBIBERTY_BUILDLINK3_MK)
LIBIBERTY_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libiberty+=	libiberty>=1.0nb1
BUILDLINK_ABI_DEPENDS.libiberty+=	libiberty>=1.0nb2
BUILDLINK_PKGSRCDIR.libiberty?=		../../devel/libiberty
BUILDLINK_DEPMETHOD.libiberty?=		build
.endif # LIBIBERTY_BUILDLINK3_MK

BUILDLINK_TREE+=	-libiberty
