# $NetBSD: buildlink3.mk,v 1.2 2009/03/20 19:24:22 joerg Exp $

BUILDLINK_TREE+=	libsigcpp1

.if !defined(LIBSIGCPP1_BUILDLINK3_MK)
LIBSIGCPP1_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libsigcpp1+=	libsigc++1>=1.2.3nb1
BUILDLINK_ABI_DEPENDS.libsigcpp1+=	libsigc++1>=1.2.7nb1
BUILDLINK_PKGSRCDIR.libsigcpp1?=	../../devel/libsigc++1
.endif # LIBSIGCPP1_BUILDLINK3_MK

BUILDLINK_TREE+=	-libsigcpp1
