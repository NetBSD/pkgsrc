# $NetBSD: buildlink3.mk,v 1.6 2022/08/12 08:43:58 pin Exp $

BUILDLINK_TREE+=	libcxx

.if !defined(LIBCXX_BUILDLINK3_MK)
LIBCXX_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libcxx+=	libcxx>=14.0.0
BUILDLINK_PKGSRCDIR.libcxx?=	../../lang/libcxx

.include "../../lang/llvm/buildlink3.mk"
.endif	# LIBCXX_BUILDLINK3_MK

BUILDLINK_TREE+=	-libcxx
