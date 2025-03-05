# $NetBSD: buildlink3.mk,v 1.11 2025/03/05 03:39:19 pho Exp $

BUILDLINK_TREE+=	hs-lpeg

.if !defined(HS_LPEG_BUILDLINK3_MK)
HS_LPEG_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-lpeg+=	hs-lpeg>=1.1.0
BUILDLINK_ABI_DEPENDS.hs-lpeg+=	hs-lpeg>=1.1.0nb4
BUILDLINK_PKGSRCDIR.hs-lpeg?=	../../devel/hs-lpeg

.include "../../lang/hs-lua/buildlink3.mk"
.endif	# HS_LPEG_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-lpeg
