# $NetBSD: buildlink3.mk,v 1.6 2017/09/18 09:53:04 maya Exp $

BUILDLINK_TREE+=	polkit-qt5

.if !defined(POLKIT_QT5_BUILDLINK3_MK)
POLKIT_QT5_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.polkit-qt5+=	polkit-qt5>=0.112.0
BUILDLINK_ABI_DEPENDS.polkit-qt5+=	polkit-qt5>=0.112.0nb5
BUILDLINK_PKGSRCDIR.polkit-qt5?=	../../security/polkit-qt5

.include "../../security/polkit/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.endif	# POLKIT_QT5_BUILDLINK3_MK

BUILDLINK_TREE+=	-polkit-qt5
