# $NetBSD: buildlink3.mk,v 1.1 2024/08/12 14:06:08 adam Exp $

BUILDLINK_TREE+=	fast_float

.if !defined(FAST_FLOAT_BUILDLINK3_MK)
FAST_FLOAT_BUILDLINK3_MK:=

BUILDLINK_DEPMETHOD.fast_float?=	build

BUILDLINK_API_DEPENDS.fast_float+=	fast_float>=6.1.3
BUILDLINK_PKGSRCDIR.fast_float?=	../../math/fast_float
.endif	# FAST_FLOAT_BUILDLINK3_MK

BUILDLINK_TREE+=	-fast_float
