# $NetBSD: buildlink.mk,v 1.1 2002/01/23 12:02:33 drochner Exp $

.include "../../lang/python/pyversion.mk"

BUILDLINK_DEPENDS.pymysqldb?= ${PYPKGPREFIX}-mysqldb-*
DEPENDS+= ${BUILDLINK_DEPENDS.pymysqldb}:../../databases/py-mysqldb
