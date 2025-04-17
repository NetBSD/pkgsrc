# $NetBSD: buildlink3.mk,v 1.13 2025/04/17 21:51:06 wiz Exp $

BUILDLINK_TREE+=	ksanecore

.if !defined(KSANECORE_BUILDLINK3_MK)
KSANECORE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ksanecore+=	ksanecore>=22.08.0
BUILDLINK_ABI_DEPENDS.ksanecore?=	ksanecore>=23.08.4nb6
BUILDLINK_PKGSRCDIR.ksanecore?=	../../graphics/ksanecore

.include "../../devel/ki18n/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.endif	# KSANECORE_BUILDLINK3_MK

BUILDLINK_TREE+=	-ksanecore
