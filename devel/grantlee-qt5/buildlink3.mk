# $NetBSD: buildlink3.mk,v 1.36 2022/07/02 16:53:11 ryoon Exp $

BUILDLINK_TREE+=	grantlee-qt5

.if !defined(GRANTLEE_QT5_BUILDLINK3_MK)
GRANTLEE_QT5_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.grantlee-qt5+=	grantlee-qt5>=5.1.0
BUILDLINK_ABI_DEPENDS.grantlee-qt5?=	grantlee-qt5>=5.2.0nb12
BUILDLINK_PKGSRCDIR.grantlee-qt5?=	../../devel/grantlee-qt5

BUILDLINK_FILES.grantlee-qt5+=		lib/grantlee/5.2/*.so

.include "../../x11/qt5-qtscript/buildlink3.mk"
.endif	# GRANTLEE_QT5_BUILDLINK3_MK

BUILDLINK_TREE+=	-grantlee-qt5
