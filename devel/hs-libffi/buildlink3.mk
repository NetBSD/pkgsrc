# $NetBSD: buildlink3.mk,v 1.9 2023/02/07 01:40:42 pho Exp $

BUILDLINK_TREE+=	hs-libffi

.if !defined(HS_LIBFFI_BUILDLINK3_MK)
HS_LIBFFI_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-libffi+=	hs-libffi>=0.2.1
BUILDLINK_ABI_DEPENDS.hs-libffi?=	hs-libffi>=0.2.1nb1
BUILDLINK_PKGSRCDIR.hs-libffi?=		../../devel/hs-libffi

.include "../../devel/libffi/buildlink3.mk"
.endif	# HS_LIBFFI_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-libffi
