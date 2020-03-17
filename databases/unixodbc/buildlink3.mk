# $NetBSD: buildlink3.mk,v 1.11 2020/03/17 18:17:06 adam Exp $

BUILDLINK_TREE+=	unixodbc

.if !defined(UNIXODBC_BUILDLINK3_MK)
UNIXODBC_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.unixodbc+=	unixodbc>=2.3.2
BUILDLINK_ABI_DEPENDS.unixodbc+=	unixodbc>=2.3.2
BUILDLINK_PKGSRCDIR.unixodbc?=		../../databases/unixodbc

.include "../../devel/libltdl/buildlink3.mk"
.endif # UNIXODBC_BUILDLINK3_MK

BUILDLINK_TREE+=	-unixodbc
