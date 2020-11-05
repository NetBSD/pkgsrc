# $NetBSD: buildlink3.mk,v 1.42 2020/11/05 09:07:01 ryoon Exp $

BUILDLINK_TREE+=	marble

.if !defined(MARBLE_BUILDLINK3_MK)
MARBLE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.marble+=	marble>=19.08.3
BUILDLINK_ABI_DEPENDS.marble?=	marble>=20.04.1nb5
BUILDLINK_PKGSRCDIR.marble?=	../../misc/marble

.include "../../x11/qt5-qtbase/buildlink3.mk"
.endif	# MARBLE_BUILDLINK3_MK

BUILDLINK_TREE+=	-marble
