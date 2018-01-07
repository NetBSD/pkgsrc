# $NetBSD: buildlink3.mk,v 1.10 2018/01/07 13:04:00 rillig Exp $

BUILDLINK_TREE+=	tdb

.if !defined(TDB_BUILDLINK3_MK)
TDB_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.tdb+=	tdb>=1.0.6
BUILDLINK_ABI_DEPENDS.tdb+=	tdb>=1.0.6nb2
BUILDLINK_PKGSRCDIR.tdb?=	../../databases/tdb
.endif # TDB_BUILDLINK3_MK

BUILDLINK_TREE+=	-tdb
