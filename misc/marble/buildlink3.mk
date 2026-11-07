# $NetBSD: buildlink3.mk,v 1.68 2026/11/07 19:11:50 wiz Exp $

BUILDLINK_TREE+=	marble

.if !defined(MARBLE_BUILDLINK3_MK)
MARBLE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.marble+=	marble>=25.08.2
BUILDLINK_ABI_DEPENDS.marble?=	marble>=26.08.0nb4
BUILDLINK_PKGSRCDIR.marble?=	../../misc/marble

.include "../../x11/qt6-qtbase/buildlink3.mk"
.endif	# MARBLE_BUILDLINK3_MK

BUILDLINK_TREE+=	-marble
