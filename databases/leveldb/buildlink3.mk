# $NetBSD: buildlink3.mk,v 1.1 2017/03/14 13:12:28 wiz Exp $

BUILDLINK_TREE+=	leveldb

.if !defined(LEVELDB_BUILDLINK3_MK)
LEVELDB_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.leveldb+=	leveldb>=1.5
BUILDLINK_PKGSRCDIR.leveldb?=	../../databases/leveldb
.endif	# LEVELDB_BUILDLINK3_MK

BUILDLINK_TREE+=	-leveldb
