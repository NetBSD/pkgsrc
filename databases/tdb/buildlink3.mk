# $NetBSD: buildlink3.mk,v 1.11 2023/08/14 05:24:02 wiz Exp $

BUILDLINK_TREE+=	tdb

.if !defined(TDB_BUILDLINK3_MK)
TDB_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.tdb+=	tdb>=1.0.6
BUILDLINK_ABI_DEPENDS.tdb+=	tdb>=1.4.9nb1
BUILDLINK_PKGSRCDIR.tdb?=	../../databases/tdb
.endif # TDB_BUILDLINK3_MK

BUILDLINK_TREE+=	-tdb
