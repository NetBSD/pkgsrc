# $NetBSD: buildlink3.mk,v 1.15 2023/10/27 04:44:02 pho Exp $

BUILDLINK_TREE+=	hs-cmdargs

.if !defined(HS_CMDARGS_BUILDLINK3_MK)
HS_CMDARGS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-cmdargs+=	hs-cmdargs>=0.10.22
BUILDLINK_ABI_DEPENDS.hs-cmdargs+=	hs-cmdargs>=0.10.22
BUILDLINK_PKGSRCDIR.hs-cmdargs?=	../../devel/hs-cmdargs
.endif	# HS_CMDARGS_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-cmdargs
