# $NetBSD: buildlink3.mk,v 1.24 2016/10/07 18:25:33 adam Exp $

BUILDLINK_TREE+=	marble

.if !defined(MARBLE_BUILDLINK3_MK)
MARBLE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.marble+=	marble>=4.8.0
BUILDLINK_ABI_DEPENDS.marble?=	marble>=4.14.3nb4
BUILDLINK_PKGSRCDIR.marble?=	../../misc/marble

.include "../../x11/kdelibs4/buildlink3.mk"
.endif	# MARBLE_BUILDLINK3_MK

BUILDLINK_TREE+=	-marble
