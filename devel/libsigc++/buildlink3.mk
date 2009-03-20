# $NetBSD: buildlink3.mk,v 1.11 2009/03/20 19:24:22 joerg Exp $

BUILDLINK_TREE+=	libsigcpp

.if !defined(LIBSIGCPP_BUILDLINK3_MK)
LIBSIGCPP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libsigcpp+=	libsigc++>=2.0.3
BUILDLINK_ABI_DEPENDS.libsigcpp+=	libsigc++>=2.0.17nb1
BUILDLINK_PKGSRCDIR.libsigcpp?=		../../devel/libsigc++
.endif # LIBSIGCPP_BUILDLINK3_MK

BUILDLINK_TREE+=	-libsigcpp
