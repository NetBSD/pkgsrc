# $NetBSD: buildlink3.mk,v 1.2 2022/01/18 02:48:22 pho Exp $

BUILDLINK_TREE+=	hs-filepattern

.if !defined(HS_FILEPATTERN_BUILDLINK3_MK)
HS_FILEPATTERN_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-filepattern+=	hs-filepattern>=0.1.2
BUILDLINK_ABI_DEPENDS.hs-filepattern+=	hs-filepattern>=0.1.2nb1
BUILDLINK_PKGSRCDIR.hs-filepattern?=	../../sysutils/hs-filepattern

.include "../../misc/hs-extra/buildlink3.mk"
.endif	# HS_FILEPATTERN_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-filepattern
