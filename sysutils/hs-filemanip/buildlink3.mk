# $NetBSD: buildlink3.mk,v 1.5 2024/05/09 01:32:36 pho Exp $

BUILDLINK_TREE+=	hs-filemanip

.if !defined(HS_FILEMANIP_BUILDLINK3_MK)
HS_FILEMANIP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-filemanip+=	hs-filemanip>=0.3.6
BUILDLINK_ABI_DEPENDS.hs-filemanip+=	hs-filemanip>=0.3.6.3nb4
BUILDLINK_PKGSRCDIR.hs-filemanip?=	../../sysutils/hs-filemanip

.include "../../devel/hs-unix-compat/buildlink3.mk"
.endif	# HS_FILEMANIP_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-filemanip
