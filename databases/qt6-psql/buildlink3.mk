# $NetBSD: buildlink3.mk,v 1.1 2022/11/24 11:41:35 nros Exp $

BUILDLINK_TREE+=	qt6-psql

.if !defined(QT6_PSQL_BUILDLINK3_MK)
QT6_PSQL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.qt6-psql+=	qt6-psql>=6.4.1
BUILDLINK_PKGSRCDIR.qt6-psql?=		../../databases/qt6-psql

BUILDLINK_LIBDIRS.qt6-psql+=		qt6/plugins/sqldrivers

.endif	# QT6_PSQL_BUILDLINK3_MK

BUILDLINK_TREE+=	-qt6-psql
