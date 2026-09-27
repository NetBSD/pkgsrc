# $NetBSD: buildlink3.mk,v 1.12 2026/09/27 11:35:22 tnn Exp $

BUILDLINK_TREE+=	poco-data-odbc

.if !defined(POCO_DATA_ODBC_BUILDLINK3_MK)
POCO_DATA_ODBC_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.poco-data-odbc+=	poco-data-odbc>=1.3.5
BUILDLINK_ABI_DEPENDS.poco-data-odbc+=	poco-data-odbc>=1.15.3nb2
BUILDLINK_PKGSRCDIR.poco-data-odbc?=	../../databases/poco-data-odbc

.include "../../databases/poco-data/buildlink3.mk"
.include "../../databases/unixodbc/buildlink3.mk"
.endif # POCO_DATA_ODBC_BUILDLINK3_MK

BUILDLINK_TREE+=	-poco-data-odbc
