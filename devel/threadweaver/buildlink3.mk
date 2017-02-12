# $NetBSD: buildlink3.mk,v 1.4 2017/02/12 06:24:42 ryoon Exp $

BUILDLINK_TREE+=	threadweaver

.if !defined(THREADWEAVER_BUILDLINK3_MK)
THREADWEAVER_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.threadweaver+=	threadweaver>=5.21.0
BUILDLINK_ABI_DEPENDS.threadweaver?=	threadweaver>=5.25.0nb3
BUILDLINK_PKGSRCDIR.threadweaver?=	../../devel/threadweaver

.include "../../x11/qt5-qtbase/buildlink3.mk"
.endif	# THREADWEAVER_BUILDLINK3_MK

BUILDLINK_TREE+=	-threadweaver
