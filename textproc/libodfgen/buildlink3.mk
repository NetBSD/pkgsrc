# $NetBSD: buildlink3.mk,v 1.27 2025/09/27 09:57:37 wiz Exp $

BUILDLINK_TREE+=	libodfgen

.if !defined(LIBODFGEN_BUILDLINK3_MK)
LIBODFGEN_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libodfgen+=	libodfgen>=0.0.3
BUILDLINK_ABI_DEPENDS.libodfgen+=	libodfgen>=0.1.7nb11
BUILDLINK_PKGSRCDIR.libodfgen?=		../../textproc/libodfgen

.include "../../converters/librevenge/buildlink3.mk"
.include "../../converters/libwpd/buildlink3.mk"
.include "../../converters/libwpg/buildlink3.mk"
.endif	# LIBODFGEN_BUILDLINK3_MK

BUILDLINK_TREE+=	-libodfgen
