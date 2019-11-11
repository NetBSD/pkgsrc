# $NetBSD: buildlink3.mk,v 1.1 2019/11/11 09:36:53 markd Exp $

BUILDLINK_TREE+=	kcontacts

.if !defined(KCONTACTS_BUILDLINK3_MK)
KCONTACTS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.kcontacts+=	kcontacts>=5.64.0
BUILDLINK_PKGSRCDIR.kcontacts?=		../../misc/kcontacts

.include "../../devel/kconfig/buildlink3.mk"
.include "../../devel/kcoreaddons/buildlink3.mk"
.include "../../devel/ki18n/buildlink3.mk"
.include "../../textproc/kcodecs/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.endif	# KCONTACTS_BUILDLINK3_MK

BUILDLINK_TREE+=	-kcontacts
