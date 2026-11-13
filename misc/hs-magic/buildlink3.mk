# $NetBSD: buildlink3.mk,v 1.7 2026/11/13 14:39:37 pho Exp $

BUILDLINK_TREE+=	hs-magic

.if !defined(HS_MAGIC_BUILDLINK3_MK)
HS_MAGIC_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-magic+=	hs-magic>=1.1
BUILDLINK_ABI_DEPENDS.hs-magic+=	hs-magic>=1.1nb6
BUILDLINK_PKGSRCDIR.hs-magic?=		../../misc/hs-magic

.include "../../sysutils/file/buildlink3.mk"
.endif	# HS_MAGIC_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-magic
