# $NetBSD: buildlink3.mk,v 1.4 2021/05/03 19:01:00 pho Exp $

BUILDLINK_TREE+=	hs-libffi

.if !defined(HS_LIBFFI_BUILDLINK3_MK)
HS_LIBFFI_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-libffi+=	hs-libffi>=0.1
BUILDLINK_ABI_DEPENDS.hs-libffi?=	hs-libffi>=0.1nb2
BUILDLINK_PKGSRCDIR.hs-libffi?=		../../devel/hs-libffi

.include "../../devel/libffi/buildlink3.mk"
.endif	# HS_LIBFFI_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-libffi
