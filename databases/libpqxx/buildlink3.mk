# $NetBSD: buildlink3.mk,v 1.10 2020/09/15 09:48:26 prlw1 Exp $

BUILDLINK_TREE+=	libpqxx

.if !defined(LIBPQXX_BUILDLINK3_MK)
LIBPQXX_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libpqxx+=	libpqxx>=7.1.2
BUILDLINK_PKGSRCDIR.libpqxx?=	../../databases/libpqxx
.endif # LIBPQXX_BUILDLINK3_MK

BUILDLINK_TREE+=	-libpqxx
