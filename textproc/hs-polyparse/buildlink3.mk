# $NetBSD: buildlink3.mk,v 1.10 2020/01/11 11:21:14 pho Exp $

BUILDLINK_TREE+=	hs-polyparse

.if !defined(HS_POLYPARSE_BUILDLINK3_MK)
HS_POLYPARSE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-polyparse+=	hs-polyparse>=1.13
BUILDLINK_ABI_DEPENDS.hs-polyparse+=	hs-polyparse>=1.13
BUILDLINK_PKGSRCDIR.hs-polyparse?=	../../textproc/hs-polyparse
.endif	# HS_POLYPARSE_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-polyparse
