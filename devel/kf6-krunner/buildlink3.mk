# $NetBSD: buildlink3.mk,v 1.1 2024/05/26 12:04:58 markd Exp $

BUILDLINK_TREE+=	kf6-krunner

.if !defined(KF6_KRUNNER_BUILDLINK3_MK)
KF6_KRUNNER_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.kf6-krunner+=	kf6-krunner>=6.2.0
BUILDLINK_PKGSRCDIR.kf6-krunner?=	../../devel/kf6-krunner

.include "../../devel/kf6-kconfig/buildlink3.mk"
.include "../../devel/kf6-kcoreaddons/buildlink3.mk"
.include "../../devel/kf6-ki18n/buildlink3.mk"
.include "../../devel/kf6-kitemmodels/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.endif	# KF6_KRUNNER_BUILDLINK3_MK

BUILDLINK_TREE+=	-kf6-krunner
