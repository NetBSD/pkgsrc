# $NetBSD: buildlink3.mk,v 1.9 2026/09/02 19:02:31 wiz Exp $

BUILDLINK_TREE+=	cairomm1.16

.if !defined(CAIROMM1.16_BUILDLINK3_MK)
CAIROMM1.16_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.cairomm1.16+=	cairomm1.16>=1.16.0
BUILDLINK_ABI_DEPENDS.cairomm1.16?=	cairomm1.16>=1.18.1nb1
BUILDLINK_PKGSRCDIR.cairomm1.16?=	../../graphics/cairomm1.16

.include "../../devel/libsigc++3/buildlink3.mk"
.include "../../graphics/cairo/buildlink3.mk"
.endif	# CAIROMM1.16_BUILDLINK3_MK

BUILDLINK_TREE+=	-cairomm1.16
