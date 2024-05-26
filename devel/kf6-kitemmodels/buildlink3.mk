# $NetBSD: buildlink3.mk,v 1.1 2024/05/26 11:44:47 markd Exp $

BUILDLINK_TREE+=	kf6-kitemmodels

.if !defined(KF6_KITEMMODELS_BUILDLINK3_MK)
KF6_KITEMMODELS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.kf6-kitemmodels+=	kf6-kitemmodels>=6.2.0
BUILDLINK_PKGSRCDIR.kf6-kitemmodels?=	../../devel/kf6-kitemmodels

.include "../../lang/qt6-qtdeclarative/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.endif	# KF6_KITEMMODELS_BUILDLINK3_MK

BUILDLINK_TREE+=	-kf6-kitemmodels
