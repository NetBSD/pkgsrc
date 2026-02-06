# $NetBSD: buildlink3.mk,v 1.3 2026/02/06 10:05:28 wiz Exp $

BUILDLINK_TREE+=	phonon-qt6

.if !defined(PHONON_QT6_BUILDLINK3_MK)
PHONON_QT6_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.phonon-qt6+=	phonon-qt6>=4.12.0
BUILDLINK_ABI_DEPENDS.phonon-qt6?=	phonon-qt6>=4.12.0nb2
BUILDLINK_PKGSRCDIR.phonon-qt6?=	../../multimedia/phonon-qt6

.include "../../devel/qt6-qttools/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.endif	# PHONON_QT6_BUILDLINK3_MK

BUILDLINK_TREE+=	-phonon-qt6
