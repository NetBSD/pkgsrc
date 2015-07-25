# $NetBSD: buildlink3.mk,v 1.7 2015/07/25 21:59:58 szptvlfn Exp $

BUILDLINK_TREE+=	hs-semigroups

.if !defined(HS_SEMIGROUPS_BUILDLINK3_MK)
HS_SEMIGROUPS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-semigroups+=	hs-semigroups>=0.15.3
BUILDLINK_ABI_DEPENDS.hs-semigroups+=	hs-semigroups>=0.15.3nb5
BUILDLINK_PKGSRCDIR.hs-semigroups?=	../../math/hs-semigroups

.include "../../devel/hs-hashable/buildlink3.mk"
.include "../../math/hs-nats/buildlink3.mk"
.include "../../devel/hs-text/buildlink3.mk"
.include "../../devel/hs-unordered-containers/buildlink3.mk"
.endif	# HS_SEMIGROUPS_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-semigroups
