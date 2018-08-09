# $NetBSD: buildlink3.mk,v 1.1 2018/08/09 14:16:08 jperkin Exp $

BUILDLINK_TREE+=	libcxx

.if !defined(LIBCXX_BUILDLINK3_MK)
LIBCXX_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libcxx+=	libcxx>=6.0.1
BUILDLINK_PKGSRCDIR.libcxx?=	../../lang/libcxx

.include "../../lang/llvm/buildlink3.mk"
.endif	# LIBCXX_BUILDLINK3_MK

BUILDLINK_TREE+=	-libcxx
