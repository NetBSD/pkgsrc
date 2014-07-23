# $NetBSD: buildlink3.mk,v 1.4 2014/07/23 06:24:28 wiz Exp $

BUILDLINK_TREE+=	libodfgen

.if !defined(LIBODFGEN_BUILDLINK3_MK)
LIBODFGEN_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libodfgen+=	libodfgen>=0.0.3
BUILDLINK_ABI_DEPENDS.libodfgen?=	libodfgen>=0.1.1
BUILDLINK_PKGSRCDIR.libodfgen?=	../../textproc/libodfgen

.include "../../converters/librevenge/buildlink3.mk"
.include "../../converters/libwpd/buildlink3.mk"
.include "../../converters/libwpg/buildlink3.mk"
.endif	# LIBODFGEN_BUILDLINK3_MK

BUILDLINK_TREE+=	-libodfgen
