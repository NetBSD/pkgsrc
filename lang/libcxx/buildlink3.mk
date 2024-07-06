# $NetBSD: buildlink3.mk,v 1.11 2024/07/06 15:45:07 adam Exp $

BUILDLINK_TREE+=	libcxx

.if !defined(LIBCXX_BUILDLINK3_MK)
LIBCXX_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libcxx+=	libcxx>=18.0.0
BUILDLINK_PKGSRCDIR.libcxx?=	../../lang/libcxx

.endif	# LIBCXX_BUILDLINK3_MK

BUILDLINK_TREE+=	-libcxx
