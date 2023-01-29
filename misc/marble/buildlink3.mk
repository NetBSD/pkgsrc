# $NetBSD: buildlink3.mk,v 1.48 2023/01/29 21:14:51 ryoon Exp $

BUILDLINK_TREE+=	marble

.if !defined(MARBLE_BUILDLINK3_MK)
MARBLE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.marble+=	marble>=19.08.3
BUILDLINK_ABI_DEPENDS.marble?=	marble>=22.08.1nb2
BUILDLINK_PKGSRCDIR.marble?=	../../misc/marble

.include "../../x11/qt5-qtbase/buildlink3.mk"
.endif	# MARBLE_BUILDLINK3_MK

BUILDLINK_TREE+=	-marble
