# $NetBSD: buildlink3.mk,v 1.21 2026/01/07 08:47:46 wiz Exp $

BUILDLINK_TREE+=	ktnef

.if !defined(KTNEF_BUILDLINK3_MK)
KTNEF_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ktnef+=	ktnef>=25.08.3
BUILDLINK_ABI_DEPENDS.ktnef?=	ktnef>=25.08.3nb1
BUILDLINK_PKGSRCDIR.ktnef?=	../../mail/ktnef

.include "../../misc/kf6-kcontacts/buildlink3.mk"
.include "../../time/kcalutils/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.endif	# KTNEF_BUILDLINK3_MK

BUILDLINK_TREE+=	-ktnef
