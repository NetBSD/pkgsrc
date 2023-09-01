# $NetBSD: buildlink3.mk,v 1.12 2023/09/01 10:49:07 nia Exp $

BUILDLINK_TREE+=	libpqxx

.if !defined(LIBPQXX_BUILDLINK3_MK)
LIBPQXX_BUILDLINK3_MK:=

USE_CXX_FEATURES+=	c++17

BUILDLINK_API_DEPENDS.libpqxx+=	libpqxx>=7.1.2
BUILDLINK_ABI_DEPENDS.libpqxx?=	libpqxx>=7.7.4nb1
BUILDLINK_PKGSRCDIR.libpqxx?=	../../databases/libpqxx
.endif # LIBPQXX_BUILDLINK3_MK

BUILDLINK_TREE+=	-libpqxx
