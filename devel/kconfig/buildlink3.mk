# $NetBSD: buildlink3.mk,v 1.28 2023/05/22 20:59:56 wiz Exp $

BUILDLINK_TREE+=	kconfig

.if !defined(KCONFIG_BUILDLINK3_MK)
KCONFIG_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.kconfig+=	kconfig>=5.18.0
BUILDLINK_ABI_DEPENDS.kconfig?=	kconfig>=5.98.0nb6
BUILDLINK_PKGSRCDIR.kconfig?=	../../devel/kconfig

BUILDLINK_FILES.kconfig+=	libexec/kf5/*

.include "../../x11/qt5-qtbase/buildlink3.mk"
.endif	# KCONFIG_BUILDLINK3_MK

BUILDLINK_TREE+=	-kconfig
