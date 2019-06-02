# $NetBSD: buildlink3.mk,v 1.1 2019/06/02 14:15:45 mef Exp $

BUILDLINK_TREE+=	double-conversion

.if !defined(DOUBLE_CONVERSION_BUILDLINK3_MK)
DOUBLE_CONVERSION_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.double-conversion+=	double-conversion>=3.0.0
BUILDLINK_ABI_DEPENDS.double-conversion+=	double-conversion>=3.0.0
BUILDLINK_PKGSRCDIR.double-conversion?=	../../math/double-conversion

.endif # DOUBLE_CONVERSION_BUILDLINK3_MK

BUILDLINK_TREE+=	-double-conversion
