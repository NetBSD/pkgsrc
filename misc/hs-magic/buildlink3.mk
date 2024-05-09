# $NetBSD: buildlink3.mk,v 1.3 2024/05/09 01:32:28 pho Exp $

BUILDLINK_TREE+=	hs-magic

.if !defined(HS_MAGIC_BUILDLINK3_MK)
HS_MAGIC_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-magic+=	hs-magic>=1.1
BUILDLINK_ABI_DEPENDS.hs-magic+=	hs-magic>=1.1nb2
BUILDLINK_PKGSRCDIR.hs-magic?=		../../misc/hs-magic

.include "../../sysutils/file/buildlink3.mk"
.endif	# HS_MAGIC_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-magic
