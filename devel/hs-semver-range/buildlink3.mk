# $NetBSD: buildlink3.mk,v 1.3 2022/08/20 08:08:18 wiz Exp $

BUILDLINK_TREE+=	hs-semver-range

.if !defined(HS_SEMVER_RANGE_BUILDLINK3_MK)
HS_SEMVER_RANGE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-semver-range+=	hs-semver-range>=0.2.8
BUILDLINK_ABI_DEPENDS.hs-semver-range+=	hs-semver-range>=0.2.8nb2
BUILDLINK_PKGSRCDIR.hs-semver-range?=	../../devel/hs-semver-range

.include "../../devel/hs-classy-prelude/buildlink3.mk"
.include "../../devel/hs-unordered-containers/buildlink3.mk"
.endif	# HS_SEMVER_RANGE_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-semver-range
