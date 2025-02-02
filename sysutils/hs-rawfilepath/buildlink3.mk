# $NetBSD: buildlink3.mk,v 1.5 2025/02/02 13:05:48 pho Exp $

BUILDLINK_TREE+=	hs-rawfilepath

.if !defined(HS_RAWFILEPATH_BUILDLINK3_MK)
HS_RAWFILEPATH_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-rawfilepath+=	hs-rawfilepath>=1.1.1
BUILDLINK_ABI_DEPENDS.hs-rawfilepath+=	hs-rawfilepath>=1.1.1nb1
BUILDLINK_PKGSRCDIR.hs-rawfilepath?=	../../sysutils/hs-rawfilepath
.endif	# HS_RAWFILEPATH_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-rawfilepath
