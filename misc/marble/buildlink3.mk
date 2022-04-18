# $NetBSD: buildlink3.mk,v 1.45 2022/04/18 19:09:59 adam Exp $

BUILDLINK_TREE+=	marble

.if !defined(MARBLE_BUILDLINK3_MK)
MARBLE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.marble+=	marble>=19.08.3
BUILDLINK_ABI_DEPENDS.marble?=	marble>=20.12.3nb11
BUILDLINK_PKGSRCDIR.marble?=	../../misc/marble

.include "../../x11/qt5-qtbase/buildlink3.mk"
.endif	# MARBLE_BUILDLINK3_MK

BUILDLINK_TREE+=	-marble
