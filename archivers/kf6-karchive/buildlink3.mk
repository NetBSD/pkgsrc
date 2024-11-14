# $NetBSD: buildlink3.mk,v 1.4 2024/11/14 22:18:37 wiz Exp $

BUILDLINK_TREE+=	kf6-karchive

.if !defined(KF6_KARCHIVE_BUILDLINK3_MK)
KF6_KARCHIVE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.kf6-karchive+=	kf6-karchive>=6.2.0
BUILDLINK_ABI_DEPENDS.kf6-karchive?=	kf6-karchive>=6.2.0nb4
BUILDLINK_PKGSRCDIR.kf6-karchive?=	../../archivers/kf6-karchive

.include "../../x11/qt6-qtbase/buildlink3.mk"
.endif	# KF6_KARCHIVE_BUILDLINK3_MK

BUILDLINK_TREE+=	-kf6-karchive
