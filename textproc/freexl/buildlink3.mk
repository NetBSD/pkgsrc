# $NetBSD: buildlink3.mk,v 1.1 2015/11/27 14:00:26 adam Exp $

BUILDLINK_TREE+=	freexl

.if !defined(FREEXL_BUILDLINK3_MK)
FREEXL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.freexl+=	freexl>=1.0.2
BUILDLINK_PKGSRCDIR.freexl?=	../../textproc/freexl

.include "../../converters/libiconv/buildlink3.mk"
.endif	# FREEXL_BUILDLINK3_MK

BUILDLINK_TREE+=	-freexl
