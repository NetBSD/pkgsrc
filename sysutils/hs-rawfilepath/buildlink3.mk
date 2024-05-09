# $NetBSD: buildlink3.mk,v 1.3 2024/05/09 01:32:37 pho Exp $

BUILDLINK_TREE+=	hs-rawfilepath

.if !defined(HS_RAWFILEPATH_BUILDLINK3_MK)
HS_RAWFILEPATH_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-rawfilepath+=	hs-rawfilepath>=1.1.0
BUILDLINK_ABI_DEPENDS.hs-rawfilepath+=	hs-rawfilepath>=1.1.0nb2
BUILDLINK_PKGSRCDIR.hs-rawfilepath?=	../../sysutils/hs-rawfilepath
.endif	# HS_RAWFILEPATH_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-rawfilepath
