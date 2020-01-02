# $NetBSD: buildlink3.mk,v 1.9 2020/01/02 03:21:09 pho Exp $

BUILDLINK_TREE+=	hs-polyparse

.if !defined(HS_POLYPARSE_BUILDLINK3_MK)
HS_POLYPARSE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-polyparse+=	hs-polyparse>=1.13
BUILDLINK_ABI_DEPENDS.hs-polyparse+=	hs-polyparse>=1.13
BUILDLINK_PKGSRCDIR.hs-polyparse?=	../../textproc/hs-polyparse

.include "../../devel/hs-fail/buildlink3.mk"
.include "../../devel/hs-text/buildlink3.mk"
.endif	# HS_POLYPARSE_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-polyparse
