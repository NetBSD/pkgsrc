# $NetBSD: buildlink3.mk,v 1.1 2024/05/26 11:22:13 markd Exp $

BUILDLINK_TREE+=	kf6-kconfig

.if !defined(KF6_KCONFIG_BUILDLINK3_MK)
KF6_KCONFIG_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.kf6-kconfig+=	kf6-kconfig>=6.2.0
BUILDLINK_PKGSRCDIR.kf6-kconfig?=	../../devel/kf6-kconfig

BUILDLINK_FILES.kf6-kconfig+=		libexec/kf6/*

.include "../../x11/qt6-qtbase/buildlink3.mk"
.endif	# KF6_KCONFIG_BUILDLINK3_MK

BUILDLINK_TREE+=	-kf6-kconfig
