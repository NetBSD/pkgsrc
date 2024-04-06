# $NetBSD: buildlink3.mk,v 1.31 2024/04/06 08:06:15 wiz Exp $

BUILDLINK_TREE+=	kdav

.if !defined(KDAV_BUILDLINK3_MK)
KDAV_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.kdav+=	kdav>=5.80.0
BUILDLINK_ABI_DEPENDS.kdav?=	kdav>=5.114.0nb1
BUILDLINK_PKGSRCDIR.kdav?=	../../misc/kdav

.include "../../devel/kio/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.endif	# KDAV_BUILDLINK3_MK

BUILDLINK_TREE+=	-kdav
