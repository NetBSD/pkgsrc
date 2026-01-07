# $NetBSD: buildlink3.mk,v 1.17 2026/01/07 08:47:22 wiz Exp $

BUILDLINK_TREE+=	ksanecore

.if !defined(KSANECORE_BUILDLINK3_MK)
KSANECORE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ksanecore+=	ksanecore>=25.08.2
BUILDLINK_ABI_DEPENDS.ksanecore?=	ksanecore>=25.08.3nb1
BUILDLINK_PKGSRCDIR.ksanecore?=		../../graphics/ksanecore

.include "../../devel/kf6-ki18n/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.endif	# KSANECORE_BUILDLINK3_MK

BUILDLINK_TREE+=	-ksanecore
