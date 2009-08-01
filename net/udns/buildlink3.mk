# $NetBSD: buildlink3.mk,v 1.1.1.1 2009/08/01 02:41:22 schnoebe Exp $

BUILDLINK_TREE+=	udns

.if !defined(UDNS_BUILDLINK3_MK)
UDNS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.udns+=	udns>=0.0.9
BUILDLINK_ABI_DEPENDS.udns+=	udns>=0.0.9
BUILDLINK_PKGSRCDIR.udns?=	../../net/udns
.endif # UDNS_BUILDLINK3_MK

BUILDLINK_TREE+=	-udns
