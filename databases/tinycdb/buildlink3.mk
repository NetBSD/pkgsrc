# $NetBSD: buildlink3.mk,v 1.7 2010/09/11 08:26:04 obache Exp $

BUILDLINK_TREE+=	tinycdb

.if !defined(TINYCDB_BUILDLINK3_MK)
TINYCDB_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.tinycdb+=	tinycdb>=0.77
BUILDLINK_PKGSRCDIR.tinycdb?=	../../databases/tinycdb
.endif # TINYCDB_BUILDLINK3_MK

BUILDLINK_TREE+=	-tinycdb
