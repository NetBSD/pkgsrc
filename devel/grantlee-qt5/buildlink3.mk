# $NetBSD: buildlink3.mk,v 1.10 2017/09/18 09:52:58 maya Exp $

BUILDLINK_TREE+=	grantlee-qt5

.if !defined(GRANTLEE_QT5_BUILDLINK3_MK)
GRANTLEE_QT5_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.grantlee-qt5+=	grantlee-qt5>=5.1.0
BUILDLINK_ABI_DEPENDS.grantlee-qt5?=	grantlee-qt5>=5.1.0nb10
BUILDLINK_PKGSRCDIR.grantlee-qt5?=	../../devel/grantlee-qt5

.include "../../x11/qt5-qtscript/buildlink3.mk"
.endif	# GRANTLEE_QT5_BUILDLINK3_MK

BUILDLINK_TREE+=	-grantlee-qt5
