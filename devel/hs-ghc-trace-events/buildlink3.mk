# $NetBSD: buildlink3.mk,v 1.7 2023/11/02 06:36:32 pho Exp $

BUILDLINK_TREE+=	hs-ghc-trace-events

.if !defined(HS_GHC_TRACE_EVENTS_BUILDLINK3_MK)
HS_GHC_TRACE_EVENTS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-ghc-trace-events+=	hs-ghc-trace-events>=0.1.2
BUILDLINK_ABI_DEPENDS.hs-ghc-trace-events+=	hs-ghc-trace-events>=0.1.2.7nb1
BUILDLINK_PKGSRCDIR.hs-ghc-trace-events?=	../../devel/hs-ghc-trace-events
.endif	# HS_GHC_TRACE_EVENTS_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-ghc-trace-events
