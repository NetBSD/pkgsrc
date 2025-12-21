# $NetBSD: buildlink3.mk,v 1.61 2025/12/21 14:38:38 markd Exp $

BUILDLINK_TREE+=	marble

.if !defined(MARBLE_BUILDLINK3_MK)
MARBLE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.marble+=	marble>=25.08.2
BUILDLINK_ABI_DEPENDS.marble?=	marble>=25.08.2
BUILDLINK_PKGSRCDIR.marble?=	../../misc/marble

.include "../../x11/qt6-qtbase/buildlink3.mk"
.endif	# MARBLE_BUILDLINK3_MK

BUILDLINK_TREE+=	-marble
