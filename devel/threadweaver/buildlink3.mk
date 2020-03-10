# $NetBSD: buildlink3.mk,v 1.16 2020/03/10 22:08:46 wiz Exp $

BUILDLINK_TREE+=	threadweaver

.if !defined(THREADWEAVER_BUILDLINK3_MK)
THREADWEAVER_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.threadweaver+=	threadweaver>=5.21.0
BUILDLINK_ABI_DEPENDS.threadweaver?=	threadweaver>=5.66.0nb2
BUILDLINK_PKGSRCDIR.threadweaver?=	../../devel/threadweaver

.include "../../x11/qt5-qtbase/buildlink3.mk"
.endif	# THREADWEAVER_BUILDLINK3_MK

BUILDLINK_TREE+=	-threadweaver
