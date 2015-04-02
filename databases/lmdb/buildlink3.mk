# $NetBSD: buildlink3.mk,v 1.1 2015/04/02 14:17:19 fhajny Exp $

BUILDLINK_TREE+=	lmdb

.if !defined(LMDB_BUILDLINK3_MK)
LMDB_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.lmdb+=	lmdb>=0.9.14
BUILDLINK_ABI_DEPENDS.lmdb+=	lmdb>=0.9.14
BUILDLINK_PKGSRCDIR.lmdb?=	../../databases/lmdb
.endif # LMDB_BUILDLINK3_MK

BUILDLINK_TREE+=	-lmdb
