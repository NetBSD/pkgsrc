# $NetBSD: buildlink3.mk,v 1.1 2022/11/24 11:26:19 nros Exp $

BUILDLINK_TREE+=	qt6-odbc

.if !defined(QT6_ODBC_BUILDLINK3_MK)
QT6_ODBC_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.qt6-odbc+=	qt6-odbc>=6.4.1
BUILDLINK_PKGSRCDIR.qt6-odbc?=		../../databases/qt6-odbc

BUILDLINK_LIBDIRS.qt6-odbc+=		qt6/plugins/sqldrivers

.endif	# QT6_ODBC_BUILDLINK3_MK

BUILDLINK_TREE+=	-qt6-odbc
