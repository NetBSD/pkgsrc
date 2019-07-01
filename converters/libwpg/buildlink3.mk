# $NetBSD: buildlink3.mk,v 1.14 2019/07/01 04:07:46 ryoon Exp $

BUILDLINK_TREE+=	libwpg

.if !defined(LIBWPG_BUILDLINK3_MK)
LIBWPG_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libwpg+=	libwpg>=0.1.3
BUILDLINK_ABI_DEPENDS.libwpg+=	libwpg>=0.3.1nb11
BUILDLINK_PKGSRCDIR.libwpg?=	../../converters/libwpg

.include "../../converters/libwpd/buildlink3.mk"
.include "../../converters/librevenge/buildlink3.mk"
.endif	# LIBWPG_BUILDLINK3_MK

BUILDLINK_TREE+=	-libwpg
