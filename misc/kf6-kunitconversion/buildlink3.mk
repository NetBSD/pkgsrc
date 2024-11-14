# $NetBSD: buildlink3.mk,v 1.4 2024/11/14 22:20:49 wiz Exp $

BUILDLINK_TREE+=	kf6-kunitconversion

.if !defined(KF6_KUNITCONVERSION_BUILDLINK3_MK)
KF6_KUNITCONVERSION_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.kf6-kunitconversion+=	kf6-kunitconversion>=6.2.0
BUILDLINK_ABI_DEPENDS.kf6-kunitconversion?=	kf6-kunitconversion>=6.2.0nb4
BUILDLINK_PKGSRCDIR.kf6-kunitconversion?=	../../misc/kf6-kunitconversion

.include "../../devel/kf6-ki18n/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.endif	# KF6_KUNITCONVERSION_BUILDLINK3_MK

BUILDLINK_TREE+=	-kf6-kunitconversion
