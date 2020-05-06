# $NetBSD: buildlink3.mk,v 1.16 2020/05/06 14:04:06 adam Exp $

BUILDLINK_TREE+=	libabw

.if !defined(LIBABW_BUILDLINK3_MK)
LIBABW_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libabw+=	libabw>=0.0.1
BUILDLINK_ABI_DEPENDS.libabw?=	libabw>=0.1.3nb1
BUILDLINK_PKGSRCDIR.libabw?=	../../converters/libabw

.include "../../converters/libwpd/buildlink3.mk"
.endif	# LIBABW_BUILDLINK3_MK

BUILDLINK_TREE+=	-libabw
