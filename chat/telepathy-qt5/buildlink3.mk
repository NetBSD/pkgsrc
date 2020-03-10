# $NetBSD: buildlink3.mk,v 1.4 2020/03/10 22:08:38 wiz Exp $
#

BUILDLINK_TREE+=	telepathy-qt5

.if !defined(TELEPATHY_QT5_BUILDLINK3_MK)
TELEPATHY_QT5_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.telepathy-qt5+=	telepathy-qt5>=0.9.8
BUILDLINK_ABI_DEPENDS.telepathy-qt5?=	telepathy-qt5>=0.9.8nb3
BUILDLINK_PKGSRCDIR.telepathy-qt5?=	../../chat/telepathy-qt5

.include "../../chat/telepathy-farstream/buildlink3.mk"
.include "../../chat/telepathy-glib/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.endif	# TELEPATHY_QT5_BUILDLINK3_MK

BUILDLINK_TREE+=	-telepathy-qt5
