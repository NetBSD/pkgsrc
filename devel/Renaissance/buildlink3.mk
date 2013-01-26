# $NetBSD: buildlink3.mk,v 1.13 2013/01/26 21:36:16 adam Exp $

BUILDLINK_TREE+=	Renaissance

.if !defined(RENAISSANCE_BUILDLINK3_MK)
RENAISSANCE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.Renaissance+=	Renaissance>=0.9.0
BUILDLINK_ABI_DEPENDS.Renaissance+=	Renaissance>=0.9.0nb2
BUILDLINK_PKGSRCDIR.Renaissance?=	../../devel/Renaissance

.include "../../x11/gnustep-back/buildlink3.mk"
.endif # RENAISSANCE_BUILDLINK3_MK

BUILDLINK_TREE+=	-Renaissance
