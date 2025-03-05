# $NetBSD: buildlink3.mk,v 1.6 2025/03/05 03:39:53 pho Exp $

BUILDLINK_TREE+=	hs-rawfilepath

.if !defined(HS_RAWFILEPATH_BUILDLINK3_MK)
HS_RAWFILEPATH_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-rawfilepath+=	hs-rawfilepath>=1.1.1
BUILDLINK_ABI_DEPENDS.hs-rawfilepath+=	hs-rawfilepath>=1.1.1nb2
BUILDLINK_PKGSRCDIR.hs-rawfilepath?=	../../sysutils/hs-rawfilepath
.endif	# HS_RAWFILEPATH_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-rawfilepath
