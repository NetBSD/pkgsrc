# $NetBSD: buildlink3.mk,v 1.12 2025/03/05 03:39:13 pho Exp $

BUILDLINK_TREE+=	hs-ghc-trace-events

.if !defined(HS_GHC_TRACE_EVENTS_BUILDLINK3_MK)
HS_GHC_TRACE_EVENTS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-ghc-trace-events+=	hs-ghc-trace-events>=0.1.2
BUILDLINK_ABI_DEPENDS.hs-ghc-trace-events+=	hs-ghc-trace-events>=0.1.2.9nb2
BUILDLINK_PKGSRCDIR.hs-ghc-trace-events?=	../../devel/hs-ghc-trace-events
.endif	# HS_GHC_TRACE_EVENTS_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-ghc-trace-events
