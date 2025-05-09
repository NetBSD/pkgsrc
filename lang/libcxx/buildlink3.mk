# $NetBSD: buildlink3.mk,v 1.13 2025/05/09 19:37:13 wiz Exp $

BUILDLINK_TREE+=	libcxx

.if !defined(LIBCXX_BUILDLINK3_MK)
LIBCXX_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libcxx+=	libcxx>=19.1.0
BUILDLINK_ABI_DEPENDS.libcxx?=	libcxx>=19.1.7nb1
BUILDLINK_PKGSRCDIR.libcxx?=	../../lang/libcxx

.include "../../lang/libcxxabi/buildlink3.mk"
.endif	# LIBCXX_BUILDLINK3_MK

BUILDLINK_TREE+=	-libcxx
