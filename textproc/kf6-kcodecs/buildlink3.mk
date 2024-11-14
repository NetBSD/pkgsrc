# $NetBSD: buildlink3.mk,v 1.4 2024/11/14 22:21:50 wiz Exp $

BUILDLINK_TREE+=	kf6-kcodecs

.if !defined(KF6_KCODECS_BUILDLINK3_MK)
KF6_KCODECS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.kf6-kcodecs+=	kf6-kcodecs>=6.2.0
BUILDLINK_ABI_DEPENDS.kf6-kcodecs?=	kf6-kcodecs>=6.2.0nb4
BUILDLINK_PKGSRCDIR.kf6-kcodecs?=	../../textproc/kf6-kcodecs

.include "../../x11/qt6-qtbase/buildlink3.mk"
.endif	# KF6_KCODECS_BUILDLINK3_MK

BUILDLINK_TREE+=	-kf6-kcodecs
