# $NetBSD: buildlink3.mk,v 1.2 2024/11/01 00:53:32 wiz Exp $

BUILDLINK_TREE+=	polkit-qt6

.if !defined(POLKIT_QT6_BUILDLINK3_MK)
POLKIT_QT6_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.polkit-qt6+=	polkit-qt6>=0.200.0
BUILDLINK_ABI_DEPENDS.polkit-qt6?=	polkit-qt6>=0.200.0nb2
BUILDLINK_PKGSRCDIR.polkit-qt6?=	../../security/polkit-qt6

.include "../../security/polkit/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.endif	# POLKIT_QT6_BUILDLINK3_MK

BUILDLINK_TREE+=	-polkit-qt6
