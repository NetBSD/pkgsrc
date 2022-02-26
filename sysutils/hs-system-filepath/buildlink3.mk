# $NetBSD: buildlink3.mk,v 1.2 2022/02/26 03:58:23 pho Exp $

BUILDLINK_TREE+=	hs-system-filepath

.if !defined(HS_SYSTEM_FILEPATH_BUILDLINK3_MK)
HS_SYSTEM_FILEPATH_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-system-filepath+=	hs-system-filepath>=0.4.14
BUILDLINK_ABI_DEPENDS.hs-system-filepath+=	hs-system-filepath>=0.4.14nb1
BUILDLINK_PKGSRCDIR.hs-system-filepath?=	../../sysutils/hs-system-filepath
.endif	# HS_SYSTEM_FILEPATH_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-system-filepath
