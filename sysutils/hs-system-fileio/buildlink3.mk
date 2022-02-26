# $NetBSD: buildlink3.mk,v 1.2 2022/02/26 03:58:23 pho Exp $

BUILDLINK_TREE+=	hs-system-fileio

.if !defined(HS_SYSTEM_FILEIO_BUILDLINK3_MK)
HS_SYSTEM_FILEIO_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-system-fileio+=	hs-system-fileio>=0.3.16
BUILDLINK_ABI_DEPENDS.hs-system-fileio+=	hs-system-fileio>=0.3.16.4nb1
BUILDLINK_PKGSRCDIR.hs-system-fileio?=		../../sysutils/hs-system-fileio

.include "../../sysutils/hs-system-filepath/buildlink3.mk"
.endif	# HS_SYSTEM_FILEIO_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-system-fileio
