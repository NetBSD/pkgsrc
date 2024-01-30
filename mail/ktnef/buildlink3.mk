# $NetBSD: buildlink3.mk,v 1.10 2024/01/30 14:22:13 ryoon Exp $

BUILDLINK_TREE+=	ktnef

.if !defined(KTNEF_BUILDLINK3_MK)
KTNEF_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ktnef+=	ktnef>=20.04.1
BUILDLINK_ABI_DEPENDS.ktnef?=	ktnef>=23.04.3nb4
BUILDLINK_PKGSRCDIR.ktnef?=	../../mail/ktnef

.include "../../misc/kcontacts/buildlink3.mk"
.include "../../time/kcalutils/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.endif	# KTNEF_BUILDLINK3_MK

BUILDLINK_TREE+=	-ktnef
