# $NetBSD: buildlink3.mk,v 1.3 2024/05/09 01:32:34 pho Exp $

BUILDLINK_TREE+=	hs-securemem

.if !defined(HS_SECUREMEM_BUILDLINK3_MK)
HS_SECUREMEM_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-securemem+=	hs-securemem>=0.1.10
BUILDLINK_ABI_DEPENDS.hs-securemem+=	hs-securemem>=0.1.10nb2
BUILDLINK_PKGSRCDIR.hs-securemem?=	../../security/hs-securemem

.include "../../devel/hs-byteable/buildlink3.mk"
.include "../../devel/hs-memory/buildlink3.mk"
.endif	# HS_SECUREMEM_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-securemem
