# $NetBSD: buildlink3.mk,v 1.9 2023/10/06 19:15:21 adam Exp $

BUILDLINK_TREE+=	libcxx

.if !defined(LIBCXX_BUILDLINK3_MK)
LIBCXX_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libcxx+=	libcxx>=16.0.0<17
BUILDLINK_PKGSRCDIR.libcxx?=	../../lang/libcxx

.endif	# LIBCXX_BUILDLINK3_MK

BUILDLINK_TREE+=	-libcxx
