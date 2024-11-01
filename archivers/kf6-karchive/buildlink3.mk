# $NetBSD: buildlink3.mk,v 1.2 2024/11/01 00:50:36 wiz Exp $

BUILDLINK_TREE+=	kf6-karchive

.if !defined(KF6_KARCHIVE_BUILDLINK3_MK)
KF6_KARCHIVE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.kf6-karchive+=	kf6-karchive>=6.2.0
BUILDLINK_ABI_DEPENDS.kf6-karchive?=	kf6-karchive>=6.2.0nb2
BUILDLINK_PKGSRCDIR.kf6-karchive?=	../../archivers/kf6-karchive

.include "../../x11/qt6-qtbase/buildlink3.mk"
.endif	# KF6_KARCHIVE_BUILDLINK3_MK

BUILDLINK_TREE+=	-kf6-karchive
