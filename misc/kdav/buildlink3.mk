# $NetBSD: buildlink3.mk,v 1.10 2020/12/04 04:56:03 riastradh Exp $

BUILDLINK_TREE+=	kdav

.if !defined(KDAV_BUILDLINK3_MK)
KDAV_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.kdav+=	kdav>=17.12.1
BUILDLINK_ABI_DEPENDS.kdav?=	kdav>=20.04.1nb4
BUILDLINK_PKGSRCDIR.kdav?=	../../misc/kdav

.include "../../devel/kio/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.endif	# KDAV_BUILDLINK3_MK

BUILDLINK_TREE+=	-kdav
