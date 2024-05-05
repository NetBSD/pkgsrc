# $NetBSD: buildlink3.mk,v 1.1 2024/05/05 05:32:04 pho Exp $

BUILDLINK_TREE+=	hs-dir-traverse

.if !defined(HS_DIR_TRAVERSE_BUILDLINK3_MK)
HS_DIR_TRAVERSE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-dir-traverse+=	hs-dir-traverse>=0.2.3
BUILDLINK_ABI_DEPENDS.hs-dir-traverse+=	hs-dir-traverse>=0.2.3.0
BUILDLINK_PKGSRCDIR.hs-dir-traverse?=	../../sysutils/hs-dir-traverse
.endif	# HS_DIR_TRAVERSE_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-dir-traverse
