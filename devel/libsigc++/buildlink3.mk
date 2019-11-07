# $NetBSD: buildlink3.mk,v 1.13 2019/11/07 13:24:50 wiz Exp $

BUILDLINK_TREE+=	libsigcpp

.if !defined(LIBSIGCPP_BUILDLINK3_MK)
LIBSIGCPP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libsigcpp+=	libsigc++>=2.0.3
BUILDLINK_ABI_DEPENDS.libsigcpp+=	libsigc++>=2.0.17nb1
BUILDLINK_PKGSRCDIR.libsigcpp?=		../../devel/libsigc++

# needs C++11
GCC_REQD+=	4.8

.endif # LIBSIGCPP_BUILDLINK3_MK

BUILDLINK_TREE+=	-libsigcpp
