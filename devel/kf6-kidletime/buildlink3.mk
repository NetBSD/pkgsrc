# $NetBSD: buildlink3.mk,v 1.1 2024/05/26 11:37:28 markd Exp $

BUILDLINK_TREE+=	kf6-kidletime

.if !defined(KF6_KIDLETIME_BUILDLINK3_MK)
KF6_KIDLETIME_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.kf6-kidletime+=	kf6-kidletime>=6.2.0
BUILDLINK_PKGSRCDIR.kf6-kidletime?=	../../devel/kf6-kidletime

.include "../../devel/qt6-qtwayland/buildlink3.mk"
.include "../../x11/libXScrnSaver/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.endif	# KF6_KIDLETIME_BUILDLINK3_MK

BUILDLINK_TREE+=	-kf6-kidletime
