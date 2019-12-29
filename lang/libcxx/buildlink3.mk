# $NetBSD: buildlink3.mk,v 1.4 2019/12/29 15:31:22 adam Exp $

BUILDLINK_TREE+=	libcxx

.if !defined(LIBCXX_BUILDLINK3_MK)
LIBCXX_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libcxx+=	libcxx>=9.0.1
BUILDLINK_PKGSRCDIR.libcxx?=	../../lang/libcxx

.include "../../lang/llvm/buildlink3.mk"
.endif	# LIBCXX_BUILDLINK3_MK

BUILDLINK_TREE+=	-libcxx
