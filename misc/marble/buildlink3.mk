# $NetBSD: buildlink3.mk,v 1.41 2020/08/17 20:17:37 leot Exp $

BUILDLINK_TREE+=	marble

.if !defined(MARBLE_BUILDLINK3_MK)
MARBLE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.marble+=	marble>=19.08.3
BUILDLINK_ABI_DEPENDS.marble?=	marble>=20.04.1nb1
BUILDLINK_PKGSRCDIR.marble?=	../../misc/marble

.include "../../x11/qt5-qtbase/buildlink3.mk"
.endif	# MARBLE_BUILDLINK3_MK

BUILDLINK_TREE+=	-marble
