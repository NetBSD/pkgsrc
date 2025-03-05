# $NetBSD: buildlink3.mk,v 1.13 2025/03/05 03:39:58 pho Exp $

BUILDLINK_TREE+=	hs-haddock-library

.if !defined(HS_HADDOCK_LIBRARY_BUILDLINK3_MK)
HS_HADDOCK_LIBRARY_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-haddock-library+=	hs-haddock-library>=1.11.0
BUILDLINK_ABI_DEPENDS.hs-haddock-library+=	hs-haddock-library>=1.11.0nb6
BUILDLINK_PKGSRCDIR.hs-haddock-library?=	../../textproc/hs-haddock-library
.endif	# HS_HADDOCK_LIBRARY_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-haddock-library
