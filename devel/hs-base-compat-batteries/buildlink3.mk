# $NetBSD: buildlink3.mk,v 1.8 2023/01/25 09:33:44 pho Exp $

BUILDLINK_TREE+=	hs-base-compat-batteries

.if !defined(HS_BASE_COMPAT_BATTERIES_BUILDLINK3_MK)
HS_BASE_COMPAT_BATTERIES_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-base-compat-batteries+=	hs-base-compat-batteries>=0.12.2
BUILDLINK_ABI_DEPENDS.hs-base-compat-batteries+=	hs-base-compat-batteries>=0.12.2
BUILDLINK_PKGSRCDIR.hs-base-compat-batteries?=		../../devel/hs-base-compat-batteries

.include "../../devel/hs-base-compat/buildlink3.mk"
.endif	# HS_BASE_COMPAT_BATTERIES_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-base-compat-batteries
