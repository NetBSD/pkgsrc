# $NetBSD: buildlink2.mk,v 1.1.2.1 2002/06/23 23:04:05 jlam Exp $

.include "../../lang/python/pyversion.mk"

BUILDLINK_PACKAGES+=		pymysqldb
BUILDLINK_DEPENDS.pymysqldb?=	${PYPKGPREFIX}-mysqldb-*
BUILDLINK_PKGSRCDIR.pymysqldb?=	../../databases/py-mysqldb
