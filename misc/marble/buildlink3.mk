# $NetBSD: buildlink3.mk,v 1.21 2015/04/17 15:52:57 adam Exp $

BUILDLINK_TREE+=	marble

.if !defined(MARBLE_BUILDLINK3_MK)
MARBLE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.marble+=	marble>=4.8.0
BUILDLINK_ABI_DEPENDS.marble?=	marble>=4.14.3nb1
BUILDLINK_PKGSRCDIR.marble?=	../../misc/marble

.include "../../x11/kdelibs4/buildlink3.mk"
.endif	# MARBLE_BUILDLINK3_MK

BUILDLINK_TREE+=	-marble
