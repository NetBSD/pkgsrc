# $NetBSD: buildlink3.mk,v 1.11 2018/11/12 03:51:23 ryoon Exp $

BUILDLINK_TREE+=	polkit-qt5

.if !defined(POLKIT_QT5_BUILDLINK3_MK)
POLKIT_QT5_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.polkit-qt5+=	polkit-qt5>=0.112.0
BUILDLINK_ABI_DEPENDS.polkit-qt5+=	polkit-qt5>=0.112.0nb10
BUILDLINK_PKGSRCDIR.polkit-qt5?=	../../security/polkit-qt5

.include "../../security/polkit/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.endif	# POLKIT_QT5_BUILDLINK3_MK

BUILDLINK_TREE+=	-polkit-qt5
