# $NetBSD: buildlink3.mk,v 1.17 2020/04/12 08:27:54 adam Exp $

BUILDLINK_TREE+=	threadweaver

.if !defined(THREADWEAVER_BUILDLINK3_MK)
THREADWEAVER_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.threadweaver+=	threadweaver>=5.21.0
BUILDLINK_ABI_DEPENDS.threadweaver?=	threadweaver>=5.66.0nb3
BUILDLINK_PKGSRCDIR.threadweaver?=	../../devel/threadweaver

.include "../../x11/qt5-qtbase/buildlink3.mk"
.endif	# THREADWEAVER_BUILDLINK3_MK

BUILDLINK_TREE+=	-threadweaver
