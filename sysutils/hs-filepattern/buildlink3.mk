# $NetBSD: buildlink3.mk,v 1.6 2023/01/25 14:41:27 pho Exp $

BUILDLINK_TREE+=	hs-filepattern

.if !defined(HS_FILEPATTERN_BUILDLINK3_MK)
HS_FILEPATTERN_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-filepattern+=	hs-filepattern>=0.1.3
BUILDLINK_ABI_DEPENDS.hs-filepattern+=	hs-filepattern>=0.1.3
BUILDLINK_PKGSRCDIR.hs-filepattern?=	../../sysutils/hs-filepattern

.include "../../misc/hs-extra/buildlink3.mk"
.endif	# HS_FILEPATTERN_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-filepattern
