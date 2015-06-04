# $NetBSD: buildlink3.mk,v 1.6 2015/06/04 20:09:00 szptvlfn Exp $

BUILDLINK_TREE+=	hs-polyparse

.if !defined(HS_POLYPARSE_BUILDLINK3_MK)
HS_POLYPARSE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-polyparse+=	hs-polyparse>=1.9
BUILDLINK_ABI_DEPENDS.hs-polyparse+=	hs-polyparse>=1.9nb5
BUILDLINK_PKGSRCDIR.hs-polyparse?=	../../textproc/hs-polyparse

.include "../../devel/hs-text/buildlink3.mk"
.endif	# HS_POLYPARSE_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-polyparse
