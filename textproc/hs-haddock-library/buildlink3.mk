# $NetBSD: buildlink3.mk,v 1.8 2023/02/07 01:41:10 pho Exp $

BUILDLINK_TREE+=	hs-haddock-library

.if !defined(HS_HADDOCK_LIBRARY_BUILDLINK3_MK)
HS_HADDOCK_LIBRARY_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-haddock-library+=	hs-haddock-library>=1.11.0
BUILDLINK_ABI_DEPENDS.hs-haddock-library+=	hs-haddock-library>=1.11.0nb1
BUILDLINK_PKGSRCDIR.hs-haddock-library?=	../../textproc/hs-haddock-library
.endif	# HS_HADDOCK_LIBRARY_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-haddock-library
