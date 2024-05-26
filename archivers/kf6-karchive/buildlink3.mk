# $NetBSD: buildlink3.mk,v 1.1 2024/05/26 11:11:01 markd Exp $

BUILDLINK_TREE+=	kf6-karchive

.if !defined(KF6_KARCHIVE_BUILDLINK3_MK)
KF6_KARCHIVE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.kf6-karchive+=	kf6-karchive>=6.2.0
BUILDLINK_PKGSRCDIR.kf6-karchive?=	../../archivers/kf6-karchive

.include "../../x11/qt6-qtbase/buildlink3.mk"
.endif	# KF6_KARCHIVE_BUILDLINK3_MK

BUILDLINK_TREE+=	-kf6-karchive
