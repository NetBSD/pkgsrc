# $NetBSD: buildlink3.mk,v 1.21 2020/11/05 09:06:54 ryoon Exp $

BUILDLINK_TREE+=	kplotting

.if !defined(KPLOTTING_BUILDLINK3_MK)
KPLOTTING_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.kplotting+=	kplotting>=5.21.0
BUILDLINK_ABI_DEPENDS.kplotting?=	kplotting>=5.70.0nb3
BUILDLINK_PKGSRCDIR.kplotting?=		../../graphics/kplotting

.include "../../x11/qt5-qtbase/buildlink3.mk"
.endif	# KPLOTTING_BUILDLINK3_MK

BUILDLINK_TREE+=	-kplotting
