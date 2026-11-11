# $NetBSD: buildlink3.mk,v 1.24 2026/11/11 11:53:49 wiz Exp $

BUILDLINK_TREE+=	ksanecore

.if !defined(KSANECORE_BUILDLINK3_MK)
KSANECORE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ksanecore+=	ksanecore>=25.08.2
BUILDLINK_ABI_DEPENDS.ksanecore?=	ksanecore>=26.08.0nb4
BUILDLINK_PKGSRCDIR.ksanecore?=		../../graphics/ksanecore

.include "../../devel/kf6-ki18n/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.endif	# KSANECORE_BUILDLINK3_MK

BUILDLINK_TREE+=	-ksanecore
