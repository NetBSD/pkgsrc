# $NetBSD: buildlink3.mk,v 1.2 2026/10/11 16:02:20 wiz Exp $

BUILDLINK_TREE+=	libclc

.if !defined(LIBCLC_BUILDLINK3_MK)
LIBCLC_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libclc+=	libclc>=21.1.0
BUILDLINK_ABI_DEPENDS.libclc?=	libclc>=22.1.8nb1
BUILDLINK_PKGSRCDIR.libclc?=	../../lang/libclc

.include "../../lang/llvm/buildlink3.mk"
.include "../../parallel/spirv-llvm-translator/buildlink3.mk"
.endif	# LIBCLC_BUILDLINK3_MK

BUILDLINK_TREE+=	-libclc
