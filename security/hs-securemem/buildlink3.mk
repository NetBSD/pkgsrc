# $NetBSD: buildlink3.mk,v 1.4 2025/02/02 13:05:45 pho Exp $

BUILDLINK_TREE+=	hs-securemem

.if !defined(HS_SECUREMEM_BUILDLINK3_MK)
HS_SECUREMEM_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-securemem+=	hs-securemem>=0.1.10
BUILDLINK_ABI_DEPENDS.hs-securemem+=	hs-securemem>=0.1.10nb3
BUILDLINK_PKGSRCDIR.hs-securemem?=	../../security/hs-securemem

.include "../../devel/hs-byteable/buildlink3.mk"
.include "../../devel/hs-memory/buildlink3.mk"
.endif	# HS_SECUREMEM_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-securemem
