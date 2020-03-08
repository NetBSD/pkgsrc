# $NetBSD: buildlink3.mk,v 1.17 2020/03/08 16:48:00 wiz Exp $

BUILDLINK_TREE+=	phonon-qt5

.if !defined(PHONON_QT5_BUILDLINK3_MK)
PHONON_QT5_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.phonon-qt5+=	phonon-qt5>=4.8.3
BUILDLINK_ABI_DEPENDS.phonon-qt5?=	phonon-qt5>=4.10.3nb3
BUILDLINK_PKGSRCDIR.phonon-qt5?=	../../multimedia/phonon-qt5

.include "../../x11/qt5-qtbase/buildlink3.mk"
.endif	# PHONON_QT5_BUILDLINK3_MK

BUILDLINK_TREE+=	-phonon-qt5
