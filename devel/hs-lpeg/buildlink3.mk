# $NetBSD: buildlink3.mk,v 1.4 2023/01/25 04:30:49 pho Exp $

BUILDLINK_TREE+=	hs-lpeg

.if !defined(HS_LPEG_BUILDLINK3_MK)
HS_LPEG_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-lpeg+=	hs-lpeg>=1.0.3
BUILDLINK_ABI_DEPENDS.hs-lpeg+=	hs-lpeg>=1.0.3
BUILDLINK_PKGSRCDIR.hs-lpeg?=	../../devel/hs-lpeg

.include "../../lang/hs-lua/buildlink3.mk"
.endif	# HS_LPEG_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-lpeg
