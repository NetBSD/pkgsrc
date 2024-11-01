# $NetBSD: buildlink3.mk,v 1.33 2024/11/01 00:52:10 wiz Exp $

BUILDLINK_TREE+=	kplotting

.if !defined(KPLOTTING_BUILDLINK3_MK)
KPLOTTING_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.kplotting+=	kplotting>=5.21.0
BUILDLINK_ABI_DEPENDS.kplotting?=	kplotting>=5.116.0nb1
BUILDLINK_PKGSRCDIR.kplotting?=		../../graphics/kplotting

.include "../../x11/qt5-qtbase/buildlink3.mk"
.endif	# KPLOTTING_BUILDLINK3_MK

BUILDLINK_TREE+=	-kplotting
