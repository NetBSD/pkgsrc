# $NetBSD: buildlink3.mk,v 1.9 2012/05/07 01:53:24 dholland Exp $

BUILDLINK_TREE+=	libiberty

.if !defined(LIBIBERTY_BUILDLINK3_MK)
LIBIBERTY_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libiberty+=	libiberty>=1.0nb1
BUILDLINK_ABI_DEPENDS.libiberty+=	libiberty>=1.0nb2
BUILDLINK_PKGSRCDIR.libiberty?=	../../devel/libiberty
BUILDLINK_DEPMETHOD.libiberty?= build
.endif # LIBIBERTY_BUILDLINK3_MK

BUILDLINK_TREE+=	-libiberty
