# $NetBSD: buildlink3.mk,v 1.15 2026/04/16 06:33:51 wiz Exp $

BUILDLINK_TREE+=	libcxx

.if !defined(LIBCXX_BUILDLINK3_MK)
LIBCXX_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libcxx+=	libcxx>=21.1.0
BUILDLINK_PKGSRCDIR.libcxx?=	../../lang/libcxx

.endif	# LIBCXX_BUILDLINK3_MK

BUILDLINK_TREE+=	-libcxx
