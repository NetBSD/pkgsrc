# $NetBSD: buildlink3.mk,v 1.1 2022/10/06 03:25:00 markd Exp $

BUILDLINK_TREE+=	ktnef

.if !defined(KTNEF_BUILDLINK3_MK)
KTNEF_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ktnef+=	ktnef>=20.04.1
BUILDLINK_PKGSRCDIR.ktnef?=	../../mail/ktnef

.include "../../misc/kcontacts/buildlink3.mk"
.include "../../time/kcalutils/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.endif	# KTNEF_BUILDLINK3_MK

BUILDLINK_TREE+=	-ktnef
