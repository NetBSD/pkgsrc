# $NetBSD: buildlink3.mk,v 1.3 2025/02/02 13:05:46 pho Exp $

BUILDLINK_TREE+=	hs-dir-traverse

.if !defined(HS_DIR_TRAVERSE_BUILDLINK3_MK)
HS_DIR_TRAVERSE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-dir-traverse+=	hs-dir-traverse>=0.2.3
BUILDLINK_ABI_DEPENDS.hs-dir-traverse+=	hs-dir-traverse>=0.2.3.0nb2
BUILDLINK_PKGSRCDIR.hs-dir-traverse?=	../../sysutils/hs-dir-traverse
.endif	# HS_DIR_TRAVERSE_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-dir-traverse
