# $NetBSD: buildlink3.mk,v 1.11 2023/11/02 06:36:43 pho Exp $

BUILDLINK_TREE+=	hs-libffi

.if !defined(HS_LIBFFI_BUILDLINK3_MK)
HS_LIBFFI_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-libffi+=	hs-libffi>=0.2.1
BUILDLINK_ABI_DEPENDS.hs-libffi?=	hs-libffi>=0.2.1nb3
BUILDLINK_PKGSRCDIR.hs-libffi?=		../../devel/hs-libffi

.include "../../devel/libffi/buildlink3.mk"
.endif	# HS_LIBFFI_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-libffi
