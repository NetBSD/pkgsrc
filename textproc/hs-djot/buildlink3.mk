# $NetBSD: buildlink3.mk,v 1.5 2025/01/30 12:16:09 pho Exp $

BUILDLINK_TREE+=	hs-djot

.if !defined(HS_DJOT_BUILDLINK3_MK)
HS_DJOT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-djot+=	hs-djot>=0.1.2
BUILDLINK_ABI_DEPENDS.hs-djot+=	hs-djot>=0.1.2.2
BUILDLINK_PKGSRCDIR.hs-djot?=	../../textproc/hs-djot

.include "../../textproc/hs-doclayout/buildlink3.mk"
.endif	# HS_DJOT_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-djot
