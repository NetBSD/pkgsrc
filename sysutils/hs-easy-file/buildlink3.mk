# $NetBSD: buildlink3.mk,v 1.3 2022/02/12 08:50:49 pho Exp $

BUILDLINK_TREE+=	hs-easy-file

.if !defined(HS_EASY_FILE_BUILDLINK3_MK)
HS_EASY_FILE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-easy-file+=	hs-easy-file>=0.2.2
BUILDLINK_ABI_DEPENDS.hs-easy-file+=	hs-easy-file>=0.2.2nb2
BUILDLINK_PKGSRCDIR.hs-easy-file?=	../../sysutils/hs-easy-file
.endif	# HS_EASY_FILE_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-easy-file
