# $NetBSD: buildlink3.mk,v 1.20 2020/06/02 08:22:51 adam Exp $

BUILDLINK_TREE+=	phonon-qt5

.if !defined(PHONON_QT5_BUILDLINK3_MK)
PHONON_QT5_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.phonon-qt5+=	phonon-qt5>=4.8.3
BUILDLINK_ABI_DEPENDS.phonon-qt5?=	phonon-qt5>=4.10.3nb6
BUILDLINK_PKGSRCDIR.phonon-qt5?=	../../multimedia/phonon-qt5

.include "../../x11/qt5-qtbase/buildlink3.mk"
.endif	# PHONON_QT5_BUILDLINK3_MK

BUILDLINK_TREE+=	-phonon-qt5
