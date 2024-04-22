# $NetBSD: buildlink3.mk,v 1.10 2024/04/22 07:05:15 adam Exp $

BUILDLINK_TREE+=	libcxx

.if !defined(LIBCXX_BUILDLINK3_MK)
LIBCXX_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libcxx+=	libcxx>=17.0.0<18
BUILDLINK_PKGSRCDIR.libcxx?=	../../lang/libcxx

.endif	# LIBCXX_BUILDLINK3_MK

BUILDLINK_TREE+=	-libcxx
