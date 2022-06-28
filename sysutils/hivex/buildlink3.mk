# $NetBSD: buildlink3.mk,v 1.2 2022/06/28 11:35:56 wiz Exp $

BUILDLINK_TREE+=	hivex

.if !defined(HIVEX_BUILDLINK3_MK)
HIVEX_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hivex+=	hivex>=1.3.15
BUILDLINK_ABI_DEPENDS.hivex?=	hivex>=1.3.18nb12
BUILDLINK_PKGSRCDIR.hivex?=	../../sysutils/hivex

.include "../../converters/libiconv/buildlink3.mk"
.endif	# HIVEX_BUILDLINK3_MK

BUILDLINK_TREE+=	-hivex
