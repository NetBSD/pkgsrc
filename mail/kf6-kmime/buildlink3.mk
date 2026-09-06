# $NetBSD: buildlink3.mk,v 1.1 2026/09/06 10:05:15 markd Exp $

BUILDLINK_TREE+=	kf6-kmime

.if !defined(KF6_KMIME_BUILDLINK3_MK)
KF6_KMIME_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.kf6-kmime+=	kf6-kmime>=6.29.0
BUILDLINK_PKGSRCDIR.kf6-kmime?=		../../mail/kf6-kmime

.include "../../devel/kf6-ki18n/buildlink3.mk"
.include "../../devel/qt6-qttools/buildlink3.mk"
.include "../../textproc/kf6-kcodecs/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.endif	# KF6_KMIME_BUILDLINK3_MK

BUILDLINK_TREE+=	-kf6-kmime
