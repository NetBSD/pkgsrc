# $NetBSD: buildlink2.mk,v 1.3 2004/03/29 05:05:33 jlam Exp $

.include "../../lang/python/pyversion.mk"

BUILDLINK_PACKAGES+=		pymysqldb
BUILDLINK_PKGBASE.pymysqldb?=	${PYPKGPREFIX}-mysqldb
BUILDLINK_DEPENDS.pymysqldb?=	${PYPKGPREFIX}-mysqldb-[0-9]*
BUILDLINK_PKGSRCDIR.pymysqldb?=	../../databases/py-mysqldb
