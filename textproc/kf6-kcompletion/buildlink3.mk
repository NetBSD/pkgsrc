# $NetBSD: buildlink3.mk,v 1.4 2024/11/14 22:21:51 wiz Exp $

BUILDLINK_TREE+=	kf6-kcompletion

.if !defined(KF6_KCOMPLETION_BUILDLINK3_MK)
KF6_KCOMPLETION_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.kf6-kcompletion+=	kf6-kcompletion>=6.2.0
BUILDLINK_ABI_DEPENDS.kf6-kcompletion?=	kf6-kcompletion>=6.2.0nb4
BUILDLINK_PKGSRCDIR.kf6-kcompletion?=	../../textproc/kf6-kcompletion

.include "../../devel/kf6-kconfig/buildlink3.mk"
.include "../../textproc/kf6-kcodecs/buildlink3.mk"
.include "../../x11/kf6-kwidgetsaddons/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.endif	# KF6_KCOMPLETION_BUILDLINK3_MK

BUILDLINK_TREE+=	-kf6-kcompletion
