# $NetBSD: buildlink3.mk,v 1.12 2018/08/16 18:54:28 adam Exp $

BUILDLINK_TREE+=	libwpg

.if !defined(LIBWPG_BUILDLINK3_MK)
LIBWPG_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libwpg+=	libwpg>=0.1.3
BUILDLINK_ABI_DEPENDS.libwpg+=	libwpg>=0.3.1nb8
BUILDLINK_PKGSRCDIR.libwpg?=	../../converters/libwpg

.include "../../converters/libwpd/buildlink3.mk"
.include "../../converters/librevenge/buildlink3.mk"
.endif	# LIBWPG_BUILDLINK3_MK

BUILDLINK_TREE+=	-libwpg
