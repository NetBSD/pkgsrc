# $NetBSD: buildlink3.mk,v 1.2 2024/05/06 10:13:01 adam Exp $

BUILDLINK_TREE+=	freexl

.if !defined(FREEXL_BUILDLINK3_MK)
FREEXL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.freexl+=	freexl>=1.0.2
BUILDLINK_PKGSRCDIR.freexl?=	../../textproc/freexl

.include "../../archivers/minizip/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"
.endif	# FREEXL_BUILDLINK3_MK

BUILDLINK_TREE+=	-freexl
