# $NetBSD: buildlink3.mk,v 1.64 2026/05/14 16:41:35 ryoon Exp $

BUILDLINK_TREE+=	marble

.if !defined(MARBLE_BUILDLINK3_MK)
MARBLE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.marble+=	marble>=25.08.2
BUILDLINK_ABI_DEPENDS.marble?=	marble>=25.08.3nb6
BUILDLINK_PKGSRCDIR.marble?=	../../misc/marble

.include "../../x11/qt6-qtbase/buildlink3.mk"
.endif	# MARBLE_BUILDLINK3_MK

BUILDLINK_TREE+=	-marble
