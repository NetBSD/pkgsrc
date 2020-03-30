# $NetBSD: buildlink3.mk,v 1.1 2020/03/30 16:33:17 riastradh Exp $

BUILDLINK_TREE+=	hs-base-compat-batteries

.if !defined(HS_BASE_COMPAT_BATTERIES_BUILDLINK3_MK)
HS_BASE_COMPAT_BATTERIES_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-base-compat-batteries+=	hs-base-compat-batteries>=0.11.0
BUILDLINK_ABI_DEPENDS.hs-base-compat-batteries+=	hs-base-compat-batteries>=0.11.0
BUILDLINK_PKGSRCDIR.hs-base-compat-batteries?=		../../devel/hs-base-compat-batteries
.endif	# HS_BASE_COMPAT_BATTERIES_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-base-compat-batteries
