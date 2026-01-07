# $NetBSD: buildlink3.mk,v 1.8 2026/01/07 08:49:03 wiz Exp $

BUILDLINK_TREE+=	kf6-kcodecs

.if !defined(KF6_KCODECS_BUILDLINK3_MK)
KF6_KCODECS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.kf6-kcodecs+=	kf6-kcodecs>=6.2.0
BUILDLINK_ABI_DEPENDS.kf6-kcodecs?=	kf6-kcodecs>=6.18.0nb2
BUILDLINK_PKGSRCDIR.kf6-kcodecs?=	../../textproc/kf6-kcodecs

.include "../../x11/qt6-qtbase/buildlink3.mk"
.endif	# KF6_KCODECS_BUILDLINK3_MK

BUILDLINK_TREE+=	-kf6-kcodecs
