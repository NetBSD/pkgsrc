# $NetBSD: buildlink3.mk,v 1.1 2026/09/02 20:22:38 adam Exp $

BUILDLINK_TREE+=	libclc

.if !defined(LIBCLC_BUILDLINK3_MK)
LIBCLC_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libclc+=	libclc>=21.1.0
BUILDLINK_PKGSRCDIR.libclc?=	../../lang/libclc

.include "../../lang/llvm/buildlink3.mk"
.include "../../parallel/spirv-llvm-translator/buildlink3.mk"
.endif	# LIBCLC_BUILDLINK3_MK

BUILDLINK_TREE+=	-libclc
