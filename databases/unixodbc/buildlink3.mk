# $NetBSD: buildlink3.mk,v 1.10 2018/01/07 13:04:00 rillig Exp $

BUILDLINK_TREE+=	unixodbc

.if !defined(UNIXODBC_BUILDLINK3_MK)
UNIXODBC_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.unixodbc+=	unixodbc>=2.3.2
BUILDLINK_ABI_DEPENDS.unixodbc+=	unixodbc>=2.3.2
BUILDLINK_PKGSRCDIR.unixodbc?=		../../databases/unixodbc
.endif # UNIXODBC_BUILDLINK3_MK

BUILDLINK_TREE+=	-unixodbc
