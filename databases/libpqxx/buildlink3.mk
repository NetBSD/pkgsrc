# $NetBSD: buildlink3.mk,v 1.11 2023/08/14 05:23:59 wiz Exp $

BUILDLINK_TREE+=	libpqxx

.if !defined(LIBPQXX_BUILDLINK3_MK)
LIBPQXX_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libpqxx+=	libpqxx>=7.1.2
BUILDLINK_ABI_DEPENDS.libpqxx?=	libpqxx>=7.7.4nb1
BUILDLINK_PKGSRCDIR.libpqxx?=	../../databases/libpqxx
.endif # LIBPQXX_BUILDLINK3_MK

BUILDLINK_TREE+=	-libpqxx
