# $NetBSD: buildlink3.mk,v 1.2 2019/06/02 08:41:58 adam Exp $

BUILDLINK_TREE+=	libcxx

.if !defined(LIBCXX_BUILDLINK3_MK)
LIBCXX_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libcxx+=	libcxx>=8.0.0
BUILDLINK_PKGSRCDIR.libcxx?=	../../lang/libcxx

.include "../../lang/llvm/buildlink3.mk"
.endif	# LIBCXX_BUILDLINK3_MK

BUILDLINK_TREE+=	-libcxx
