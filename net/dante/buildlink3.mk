# $NetBSD: buildlink3.mk,v 1.7 2009/03/20 19:25:07 joerg Exp $

BUILDLINK_TREE+=	dante

.if !defined(DANTE_BUILDLINK3_MK)
DANTE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.dante+=	dante>=1.1.13
BUILDLINK_ABI_DEPENDS.dante+=	dante>=1.1.14nb1
BUILDLINK_PKGSRCDIR.dante?=	../../net/dante
.endif # DANTE_BUILDLINK3_MK

BUILDLINK_TREE+=	-dante
