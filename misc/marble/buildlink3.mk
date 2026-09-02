# $NetBSD: buildlink3.mk,v 1.65 2026/09/02 19:03:34 wiz Exp $

BUILDLINK_TREE+=	marble

.if !defined(MARBLE_BUILDLINK3_MK)
MARBLE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.marble+=	marble>=25.08.2
BUILDLINK_ABI_DEPENDS.marble?=	marble>=25.08.3nb11
BUILDLINK_PKGSRCDIR.marble?=	../../misc/marble

.include "../../x11/qt6-qtbase/buildlink3.mk"
.endif	# MARBLE_BUILDLINK3_MK

BUILDLINK_TREE+=	-marble
