# $NetBSD: buildlink3.mk,v 1.7 2024/12/27 08:19:33 wiz Exp $

BUILDLINK_TREE+=	kf6-knotifications

.if !defined(KF6_KNOTIFICATIONS_BUILDLINK3_MK)
KF6_KNOTIFICATIONS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.kf6-knotifications+=	kf6-knotifications>=6.2.0
BUILDLINK_ABI_DEPENDS.kf6-knotifications?=	kf6-knotifications>=6.8.0nb1
BUILDLINK_PKGSRCDIR.kf6-knotifications?=	../../devel/kf6-knotifications

.include "../../audio/libcanberra/buildlink3.mk"
.include "../../devel/kf6-kconfig/buildlink3.mk"
.include "../../lang/qt6-qtdeclarative/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.endif	# KF6_KNOTIFICATIONS_BUILDLINK3_MK

BUILDLINK_TREE+=	-kf6-knotifications
