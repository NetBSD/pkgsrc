# $NetBSD: buildlink3.mk,v 1.8 2026/11/13 14:39:46 pho Exp $

BUILDLINK_TREE+=	hs-rawfilepath

.if !defined(HS_RAWFILEPATH_BUILDLINK3_MK)
HS_RAWFILEPATH_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-rawfilepath+=	hs-rawfilepath>=1.1.1
BUILDLINK_ABI_DEPENDS.hs-rawfilepath+=	hs-rawfilepath>=1.1.1nb4
BUILDLINK_PKGSRCDIR.hs-rawfilepath?=	../../sysutils/hs-rawfilepath
.endif	# HS_RAWFILEPATH_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-rawfilepath
