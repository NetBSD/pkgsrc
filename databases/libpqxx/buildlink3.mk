# $NetBSD: buildlink3.mk,v 1.9 2018/05/03 12:58:24 prlw1 Exp $

BUILDLINK_TREE+=	libpqxx

.if !defined(LIBPQXX_BUILDLINK3_MK)
LIBPQXX_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libpqxx+=	libpqxx>=6.2.2
BUILDLINK_PKGSRCDIR.libpqxx?=	../../databases/libpqxx
.endif # LIBPQXX_BUILDLINK3_MK

BUILDLINK_TREE+=	-libpqxx
