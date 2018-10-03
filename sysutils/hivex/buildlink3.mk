# $NetBSD: buildlink3.mk,v 1.1 2018/10/03 20:09:00 tnn Exp $

BUILDLINK_TREE+=	hivex

.if !defined(HIVEX_BUILDLINK3_MK)
HIVEX_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hivex+=	hivex>=1.3.15
BUILDLINK_PKGSRCDIR.hivex?=	../../sysutils/hivex

.include "../../converters/libiconv/buildlink3.mk"
.endif	# HIVEX_BUILDLINK3_MK

BUILDLINK_TREE+=	-hivex
