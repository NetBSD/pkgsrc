# $NetBSD: buildlink3.mk,v 1.8 2026/01/07 08:46:35 wiz Exp $

BUILDLINK_TREE+=	kf6-kidletime

.if !defined(KF6_KIDLETIME_BUILDLINK3_MK)
KF6_KIDLETIME_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.kf6-kidletime+=	kf6-kidletime>=6.2.0
BUILDLINK_ABI_DEPENDS.kf6-kidletime?=	kf6-kidletime>=6.18.0nb2
BUILDLINK_PKGSRCDIR.kf6-kidletime?=	../../devel/kf6-kidletime

.include "../../devel/qt6-qtwayland/buildlink3.mk"
.include "../../x11/libXScrnSaver/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.endif	# KF6_KIDLETIME_BUILDLINK3_MK

BUILDLINK_TREE+=	-kf6-kidletime
