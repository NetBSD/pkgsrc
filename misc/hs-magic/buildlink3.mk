# $NetBSD: buildlink3.mk,v 1.6 2025/08/13 11:07:17 pho Exp $

BUILDLINK_TREE+=	hs-magic

.if !defined(HS_MAGIC_BUILDLINK3_MK)
HS_MAGIC_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-magic+=	hs-magic>=1.1
BUILDLINK_ABI_DEPENDS.hs-magic+=	hs-magic>=1.1nb5
BUILDLINK_PKGSRCDIR.hs-magic?=		../../misc/hs-magic

.include "../../sysutils/file/buildlink3.mk"
.endif	# HS_MAGIC_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-magic
