# $NetBSD: buildlink3.mk,v 1.2 2021/04/24 15:31:23 pho Exp $

BUILDLINK_TREE+=	hs-haddock-library

.if !defined(HS_HADDOCK_LIBRARY_BUILDLINK3_MK)
HS_HADDOCK_LIBRARY_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-haddock-library+=	hs-haddock-library>=1.10.0
BUILDLINK_ABI_DEPENDS.hs-haddock-library+=	hs-haddock-library>=1.10.0
BUILDLINK_PKGSRCDIR.hs-haddock-library?=	../../textproc/hs-haddock-library
.endif	# HS_HADDOCK_LIBRARY_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-haddock-library
