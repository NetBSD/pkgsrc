# $NetBSD: buildlink3.mk,v 1.3 2024/11/01 12:52:10 wiz Exp $

BUILDLINK_TREE+=	kf6-kcrash

.if !defined(KF6_KCRASH_BUILDLINK3_MK)
KF6_KCRASH_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.kf6-kcrash+=	kf6-kcrash>=6.2.0
BUILDLINK_ABI_DEPENDS.kf6-kcrash?=	kf6-kcrash>=6.2.0nb3
BUILDLINK_PKGSRCDIR.kf6-kcrash?=	../../devel/kf6-kcrash

.include "../../devel/kf6-kcoreaddons/buildlink3.mk"
.include "../../x11/kf6-kwindowsystem/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.endif	# KF6_KCRASH_BUILDLINK3_MK

BUILDLINK_TREE+=	-kf6-kcrash
