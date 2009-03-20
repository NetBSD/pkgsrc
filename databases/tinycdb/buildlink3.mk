# $NetBSD: buildlink3.mk,v 1.6 2009/03/20 19:24:08 joerg Exp $

BUILDLINK_TREE+=	tinycdb

.if !defined(TINYCDB_BUILDLINK3_MK)
TINYCDB_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.tinycdb+=	tinycdb>=0.75
BUILDLINK_DEPMETHOD.tinycdb?=	build
BUILDLINK_PKGSRCDIR.tinycdb?=	../../databases/tinycdb
.endif # TINYCDB_BUILDLINK3_MK

BUILDLINK_TREE+=	-tinycdb
