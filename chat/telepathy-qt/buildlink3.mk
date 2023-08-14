# $NetBSD: buildlink3.mk,v 1.2 2023/08/14 05:23:56 wiz Exp $

BUILDLINK_TREE+=	telepathy-qt

.if !defined(TELEPATHY_QT_BUILDLINK3_MK)
TELEPATHY_QT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.telepathy-qt+=	telepathy-qt>=0.9.6
BUILDLINK_ABI_DEPENDS.telepathy-qt?=	telepathy-qt>=0.9.6.1nb10
BUILDLINK_PKGSRCDIR.telepathy-qt?=	../../chat/telepathy-qt

#.include "../../chat/telepathy-glib/buildlink3.mk"
#.include "../../devel/glib2/buildlink3.mk"
#.include "../../sysutils/dbus/buildlink3.mk"
#.include "../../sysutils/dbus-glib/buildlink3.mk"
#.include "../../x11/qt4-libs/buildlink3.mk"
#.include "../../x11/qt4-qdbus/buildlink3.mk"
.endif	# TELEPATHY_QT_BUILDLINK3_MK

BUILDLINK_TREE+=	-telepathy-qt
