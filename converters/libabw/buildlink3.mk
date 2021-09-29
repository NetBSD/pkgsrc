# $NetBSD: buildlink3.mk,v 1.19 2021/09/29 19:00:03 adam Exp $

BUILDLINK_TREE+=	libabw

.if !defined(LIBABW_BUILDLINK3_MK)
LIBABW_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libabw+=	libabw>=0.0.1
BUILDLINK_ABI_DEPENDS.libabw?=	libabw>=0.1.3nb9
BUILDLINK_PKGSRCDIR.libabw?=	../../converters/libabw

.include "../../converters/libwpd/buildlink3.mk"
.endif	# LIBABW_BUILDLINK3_MK

BUILDLINK_TREE+=	-libabw
