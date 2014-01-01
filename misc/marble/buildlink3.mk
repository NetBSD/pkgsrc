# $NetBSD: buildlink3.mk,v 1.15 2014/01/01 11:52:04 wiz Exp $

BUILDLINK_TREE+=	marble

.if !defined(MARBLE_BUILDLINK3_MK)
MARBLE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.marble+=	marble>=4.8.0
BUILDLINK_ABI_DEPENDS.marble?=	marble>=4.11.3nb1
BUILDLINK_PKGSRCDIR.marble?=	../../misc/marble

.include "../../x11/kdelibs4/buildlink3.mk"
.endif	# MARBLE_BUILDLINK3_MK

BUILDLINK_TREE+=	-marble
