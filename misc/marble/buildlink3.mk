# $NetBSD: buildlink3.mk,v 1.14 2013/07/05 13:29:39 ryoon Exp $

BUILDLINK_TREE+=	marble

.if !defined(MARBLE_BUILDLINK3_MK)
MARBLE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.marble+=	marble>=4.8.0
BUILDLINK_ABI_DEPENDS.marble?=	marble>=4.10.3nb4
BUILDLINK_PKGSRCDIR.marble?=	../../misc/marble

.include "../../x11/kdelibs4/buildlink3.mk"
.endif	# MARBLE_BUILDLINK3_MK

BUILDLINK_TREE+=	-marble
