# $NetBSD: buildlink3.mk,v 1.7 2009/03/20 19:24:05 joerg Exp $

BUILDLINK_TREE+=	libpqxx

.if !defined(LIBPQXX_BUILDLINK3_MK)
LIBPQXX_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libpqxx+=	libpqxx>=2.5.0
BUILDLINK_ABI_DEPENDS.libpqxx?=	libpqxx>=2.5.4nb1
BUILDLINK_PKGSRCDIR.libpqxx?=	../../databases/libpqxx
.endif # LIBPQXX_BUILDLINK3_MK

BUILDLINK_TREE+=	-libpqxx
