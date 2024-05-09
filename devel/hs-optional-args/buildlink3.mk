# $NetBSD: buildlink3.mk,v 1.6 2024/05/09 01:32:06 pho Exp $

BUILDLINK_TREE+=	hs-optional-args

.if !defined(HS_OPTIONAL_ARGS_BUILDLINK3_MK)
HS_OPTIONAL_ARGS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-optional-args+=	hs-optional-args>=1.0.2
BUILDLINK_ABI_DEPENDS.hs-optional-args+=	hs-optional-args>=1.0.2nb5
BUILDLINK_PKGSRCDIR.hs-optional-args?=		../../devel/hs-optional-args
.endif	# HS_OPTIONAL_ARGS_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-optional-args
