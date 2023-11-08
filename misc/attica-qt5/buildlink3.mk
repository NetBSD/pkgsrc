# $NetBSD: buildlink3.mk,v 1.28 2023/11/08 13:20:04 wiz Exp $

BUILDLINK_TREE+=	attica-qt5

.if !defined(ATTICA_QT5_BUILDLINK3_MK)
ATTICA_QT5_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.attica-qt5+=	attica-qt5>=5.18.0
BUILDLINK_ABI_DEPENDS.attica-qt5?=	attica-qt5>=5.108.0nb2
BUILDLINK_PKGSRCDIR.attica-qt5?=	../../misc/attica-qt5

.include "../../x11/qt5-qtbase/buildlink3.mk"
.endif	# ATTICA_QT5_BUILDLINK3_MK

BUILDLINK_TREE+=	-attica-qt5
