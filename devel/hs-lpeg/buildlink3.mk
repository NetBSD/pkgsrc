# $NetBSD: buildlink3.mk,v 1.8 2023/11/02 06:36:44 pho Exp $

BUILDLINK_TREE+=	hs-lpeg

.if !defined(HS_LPEG_BUILDLINK3_MK)
HS_LPEG_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-lpeg+=	hs-lpeg>=1.1.0
BUILDLINK_ABI_DEPENDS.hs-lpeg+=	hs-lpeg>=1.1.0nb1
BUILDLINK_PKGSRCDIR.hs-lpeg?=	../../devel/hs-lpeg

.include "../../lang/hs-lua/buildlink3.mk"
.endif	# HS_LPEG_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-lpeg
