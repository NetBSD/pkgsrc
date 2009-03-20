# $NetBSD: buildlink3.mk,v 1.11 2009/03/20 19:24:08 joerg Exp $

BUILDLINK_TREE+=	Renaissance

.if !defined(RENAISSANCE_BUILDLINK3_MK)
RENAISSANCE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.Renaissance+=		Renaissance>=0.7.0
BUILDLINK_ABI_DEPENDS.Renaissance+=	Renaissance>=0.8.0nb7
BUILDLINK_PKGSRCDIR.Renaissance?=	../../devel/Renaissance

.include "../../x11/gnustep-back/buildlink3.mk"
.endif # RENAISSANCE_BUILDLINK3_MK

BUILDLINK_TREE+=	-Renaissance
