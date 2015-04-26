# $NetBSD: buildlink3.mk,v 1.6 2015/04/26 11:52:18 ryoon Exp $

BUILDLINK_TREE+=	poco-data-odbc

.if !defined(POCO_DATA_ODBC_BUILDLINK3_MK)
POCO_DATA_ODBC_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.poco-data-odbc+=	poco-data-odbc>=1.3.5
BUILDLINK_ABI_DEPENDS.poco-data-odbc+=	poco-data-odbc>=1.4.2p1nb3
BUILDLINK_PKGSRCDIR.poco-data-odbc?=	../../databases/poco-data-odbc

.include "../../databases/unixodbc/buildlink3.mk"
.include "../../databases/poco-data/buildlink3.mk"
.endif # POCO_DATA_ODBC_BUILDLINK3_MK

BUILDLINK_TREE+=	-poco-data-odbc
