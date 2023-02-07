# $NetBSD: buildlink3.mk,v 1.4 2023/02/07 01:41:06 pho Exp $

BUILDLINK_TREE+=	hs-opentelemetry

.if !defined(HS_OPENTELEMETRY_BUILDLINK3_MK)
HS_OPENTELEMETRY_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-opentelemetry+=	hs-opentelemetry>=0.8.0
BUILDLINK_ABI_DEPENDS.hs-opentelemetry+=	hs-opentelemetry>=0.8.0nb1
BUILDLINK_PKGSRCDIR.hs-opentelemetry?=		../../sysutils/hs-opentelemetry

.include "../../devel/hs-ghc-trace-events/buildlink3.mk"
.include "../../devel/hs-hashable/buildlink3.mk"
.endif	# HS_OPENTELEMETRY_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-opentelemetry
