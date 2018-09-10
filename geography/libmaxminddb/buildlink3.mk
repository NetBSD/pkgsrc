# $NetBSD: buildlink3.mk,v 1.1 2018/09/10 20:57:16 fhajny Exp $

BUILDLINK_TREE+=	libmaxminddb

.if !defined(LIBMAXMINDDB_BUILDLINK3_MK)
LIBMAXMINDDB_BUILDLINK3_MK:=

BUILDLINK_ABI_DEPENDS.libmaxminddb+=	libmaxminddb>=1.3.0
BUILDLINK_API_DEPENDS.libmaxminddb+=	libmaxminddb>=1.3.0
BUILDLINK_PKGSRCDIR.libmaxminddb?=	../../geography/libmaxminddb
.endif # LIBMAXMINDDB_BUILDLINK3_MK

BUILDLINK_TREE+=	-libmaxminddb
