# $NetBSD: buildlink3.mk,v 1.2 2020/04/06 09:11:13 wiz Exp $

BUILDLINK_TREE+=	libsigcpp3

.if !defined(LIBSIGCPP3_BUILDLINK3_MK)
LIBSIGCPP3_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libsigcpp3+=	libsigc++3>=3.0.0
BUILDLINK_PKGSRCDIR.libsigcpp3?=	../../devel/libsigc++3

# needs C++11
GCC_REQD+=	4.8

.endif # LIBSIGCPP3_BUILDLINK3_MK

BUILDLINK_TREE+=	-libsigcpp3
