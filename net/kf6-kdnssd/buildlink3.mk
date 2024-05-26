# $NetBSD: buildlink3.mk,v 1.1 2024/05/26 12:40:06 markd Exp $

BUILDLINK_TREE+=	kf6-kdnssd

.if !defined(KF6_KDNSSD_BUILDLINK3_MK)
KF6_KDNSSD_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.kf6-kdnssd+=	kf6-kdnssd>=6.2.0
BUILDLINK_PKGSRCDIR.kf6-kdnssd?=	../../net/kf6-kdnssd

.include "../../net/avahi/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.endif	# KF6_KDNSSD_BUILDLINK3_MK

BUILDLINK_TREE+=	-kf6-kdnssd
