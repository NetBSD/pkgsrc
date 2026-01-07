# $NetBSD: buildlink3.mk,v 1.26 2026/01/07 08:47:56 wiz Exp $

BUILDLINK_TREE+=	kcontacts

.if !defined(KCONTACTS_BUILDLINK3_MK)
KCONTACTS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.kcontacts+=	kcontacts>=5.64.0
BUILDLINK_ABI_DEPENDS.kcontacts?=		kcontacts>=5.116.0nb7
BUILDLINK_PKGSRCDIR.kcontacts?=		../../misc/kcontacts

.include "../../devel/kconfig/buildlink3.mk"
.include "../../devel/kcoreaddons/buildlink3.mk"
.include "../../devel/ki18n/buildlink3.mk"
.include "../../textproc/kcodecs/buildlink3.mk"
.include "../../x11/qt5-qtdeclarative/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.endif	# KCONTACTS_BUILDLINK3_MK

BUILDLINK_TREE+=	-kcontacts
