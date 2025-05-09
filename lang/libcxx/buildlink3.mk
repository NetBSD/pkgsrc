# $NetBSD: buildlink3.mk,v 1.12 2025/05/09 05:51:24 adam Exp $

BUILDLINK_TREE+=	libcxx

.if !defined(LIBCXX_BUILDLINK3_MK)
LIBCXX_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libcxx+=	libcxx>=19.1.0
BUILDLINK_PKGSRCDIR.libcxx?=	../../lang/libcxx

.include "../../lang/libcxxabi/buildlink3.mk"
.endif	# LIBCXX_BUILDLINK3_MK

BUILDLINK_TREE+=	-libcxx
