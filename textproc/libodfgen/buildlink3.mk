# $NetBSD: buildlink3.mk,v 1.2 2014/02/02 09:48:31 ryoon Exp $

BUILDLINK_TREE+=	libodfgen

.if !defined(LIBODFGEN_BUILDLINK3_MK)
LIBODFGEN_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libodfgen+=	libodfgen>=0.0.3
BUILDLINK_PKGSRCDIR.libodfgen?=	../../textproc/libodfgen

.include "../../converters/libwpd/buildlink3.mk"
.include "../../converters/libwpg/buildlink3.mk"
.endif	# LIBODFGEN_BUILDLINK3_MK

BUILDLINK_TREE+=	-libodfgen
