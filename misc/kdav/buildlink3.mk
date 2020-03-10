# $NetBSD: buildlink3.mk,v 1.4 2020/03/10 22:08:54 wiz Exp $

BUILDLINK_TREE+=	kdav

.if !defined(KDAV_BUILDLINK3_MK)
KDAV_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.kdav+=	kdav>=17.12.1
BUILDLINK_ABI_DEPENDS.kdav?=	kdav>=19.12.1nb2
BUILDLINK_PKGSRCDIR.kdav?=	../../misc/kdav

.include "../../devel/kio/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.endif	# KDAV_BUILDLINK3_MK

BUILDLINK_TREE+=	-kdav
