# $NetBSD: buildlink3.mk,v 1.1 2024/05/26 12:44:55 markd Exp $

BUILDLINK_TREE+=	kf6-kauth

.if !defined(KF6_KAUTH_BUILDLINK3_MK)
KF6_KAUTH_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.kf6-kauth+=	kf6-kauth>=6.2.0
BUILDLINK_PKGSRCDIR.kf6-kauth?=		../../security/kf6-kauth

BUILDLINK_FILES.kf6-kauth+=	libexec/kf6/kauth/*
BUILDLINK_FILES.kf6-kauth+=	share/kf6/kauth/dbus*.stub

.include "../../devel/kf6-kcoreaddons/buildlink3.mk"
.include "../../security/polkit-qt6/buildlink3.mk"
.include "../../x11/kf6-kwindowsystem/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.endif	# KF6_KAUTH_BUILDLINK3_MK

BUILDLINK_TREE+=	-kf6-kauth
