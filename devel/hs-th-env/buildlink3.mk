# $NetBSD: buildlink3.mk,v 1.1 2022/02/24 01:23:58 pho Exp $

BUILDLINK_TREE+=	hs-th-env

.if !defined(HS_TH_ENV_BUILDLINK3_MK)
HS_TH_ENV_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-th-env+=	hs-th-env>=0.1.0.3
BUILDLINK_ABI_DEPENDS.hs-th-env+=	hs-th-env>=0.1.0.3
BUILDLINK_PKGSRCDIR.hs-th-env?=		../../devel/hs-th-env

.include "../../devel/hs-th-compat/buildlink3.mk"
.endif	# HS_TH_ENV_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-th-env
