# $NetBSD: buildlink3.mk,v 1.2 2024/05/09 01:32:35 pho Exp $

BUILDLINK_TREE+=	hs-dir-traverse

.if !defined(HS_DIR_TRAVERSE_BUILDLINK3_MK)
HS_DIR_TRAVERSE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-dir-traverse+=	hs-dir-traverse>=0.2.3
BUILDLINK_ABI_DEPENDS.hs-dir-traverse+=	hs-dir-traverse>=0.2.3.0nb1
BUILDLINK_PKGSRCDIR.hs-dir-traverse?=	../../sysutils/hs-dir-traverse
.endif	# HS_DIR_TRAVERSE_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-dir-traverse
