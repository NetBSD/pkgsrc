# $NetBSD: buildlink3.mk,v 1.4 2024/11/14 22:19:26 wiz Exp $

BUILDLINK_TREE+=	kf6-kitemmodels

.if !defined(KF6_KITEMMODELS_BUILDLINK3_MK)
KF6_KITEMMODELS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.kf6-kitemmodels+=	kf6-kitemmodels>=6.2.0
BUILDLINK_ABI_DEPENDS.kf6-kitemmodels?=	kf6-kitemmodels>=6.2.0nb4
BUILDLINK_PKGSRCDIR.kf6-kitemmodels?=	../../devel/kf6-kitemmodels

.include "../../lang/qt6-qtdeclarative/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.endif	# KF6_KITEMMODELS_BUILDLINK3_MK

BUILDLINK_TREE+=	-kf6-kitemmodels
