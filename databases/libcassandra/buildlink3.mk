# $NetBSD: buildlink3.mk,v 1.3 2022/06/28 11:31:17 wiz Exp $

BUILDLINK_TREE+=	libcassandra

.if !defined(LIBCASSANDRA_BUILDLINK3_MK)
LIBCASSANDRA_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libcassandra+=	libcassandra>=20100501
BUILDLINK_ABI_DEPENDS.libcassandra+=	libcassandra>=20101010nb43
BUILDLINK_PKGSRCDIR.libcassandra?=	../../databases/libcassandra
.endif # LIBCASSANDRA_BUILDLINK3_MK

BUILDLINK_TREE+=	-libcassandra
