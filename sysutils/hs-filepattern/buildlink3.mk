# $NetBSD: buildlink3.mk,v 1.9 2023/11/02 06:37:24 pho Exp $

BUILDLINK_TREE+=	hs-filepattern

.if !defined(HS_FILEPATTERN_BUILDLINK3_MK)
HS_FILEPATTERN_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-filepattern+=	hs-filepattern>=0.1.3
BUILDLINK_ABI_DEPENDS.hs-filepattern+=	hs-filepattern>=0.1.3nb3
BUILDLINK_PKGSRCDIR.hs-filepattern?=	../../sysutils/hs-filepattern

.include "../../misc/hs-extra/buildlink3.mk"
.endif	# HS_FILEPATTERN_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-filepattern
