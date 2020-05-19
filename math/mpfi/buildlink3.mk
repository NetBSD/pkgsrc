# $NetBSD: buildlink3.mk,v 1.1 2020/05/19 14:44:04 riastradh Exp $

BUILDLINK_TREE+=	mpfi

.if !defined(MPFI_BUILDLINK3_MK)
MPFI_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.mpfi+=	mpfi>=1.5.4
BUILDLINK_ABI_DEPENDS.mpfi+=	mpfi>=1.5.4
BUILDLINK_PKGSRCDIR.mpfi?=	../../math/mpfi

.include "../../math/mpfr/buildlink3.mk"
.endif # MPFI_BUILDLINK3_MK

BUILDLINK_TREE+=	-mpfi
