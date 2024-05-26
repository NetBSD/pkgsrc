# $NetBSD: buildlink3.mk,v 1.1 2024/05/26 13:00:35 markd Exp $

BUILDLINK_TREE+=	kf6-solid

.if !defined(KF6_SOLID_BUILDLINK3_MK)
KF6_SOLID_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.kf6-solid+=	kf6-solid>=6.2.0
BUILDLINK_PKGSRCDIR.kf6-solid?=		../../sysutils/kf6-solid

.include "../../lang/qt6-qtdeclarative/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.endif	# KF6_SOLID_BUILDLINK3_MK

BUILDLINK_TREE+=	-kf6-solid
