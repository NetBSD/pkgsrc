# $NetBSD: buildlink3.mk,v 1.21 2022/09/11 12:51:09 wiz Exp $

BUILDLINK_TREE+=	kdav

.if !defined(KDAV_BUILDLINK3_MK)
KDAV_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.kdav+=	kdav>=5.80.0
BUILDLINK_ABI_DEPENDS.kdav?=	kdav>=5.93.0nb3
BUILDLINK_PKGSRCDIR.kdav?=	../../misc/kdav

.include "../../devel/kio/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.endif	# KDAV_BUILDLINK3_MK

BUILDLINK_TREE+=	-kdav
