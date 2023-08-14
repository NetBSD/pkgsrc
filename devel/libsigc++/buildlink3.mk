# $NetBSD: buildlink3.mk,v 1.15 2023/08/14 05:24:12 wiz Exp $

BUILDLINK_TREE+=	libsigcpp

.if !defined(LIBSIGCPP_BUILDLINK3_MK)
LIBSIGCPP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libsigcpp+=	libsigc++>=2.0.3
BUILDLINK_ABI_DEPENDS.libsigcpp+=	libsigc++>=2.10.8nb1
BUILDLINK_PKGSRCDIR.libsigcpp?=		../../devel/libsigc++

USE_CXX_FEATURES+=	c++11

.endif # LIBSIGCPP_BUILDLINK3_MK

BUILDLINK_TREE+=	-libsigcpp
