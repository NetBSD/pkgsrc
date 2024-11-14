# $NetBSD: buildlink3.mk,v 1.4 2024/11/14 22:20:11 wiz Exp $

BUILDLINK_TREE+=	kf6-prison

.if !defined(KF6_PRISON_BUILDLINK3_MK)
KF6_PRISON_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.kf6-prison+=	kf6-prison>=6.2.0
BUILDLINK_ABI_DEPENDS.kf6-prison?=	kf6-prison>=6.2.0nb4
BUILDLINK_PKGSRCDIR.kf6-prison?=	../../graphics/kf6-prison

.include "../../x11/qt6-qtbase/buildlink3.mk"
.endif	# KF6_PRISON_BUILDLINK3_MK

BUILDLINK_TREE+=	-kf6-prison
