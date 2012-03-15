# $NetBSD: buildlink3.mk,v 1.10 2012/03/15 14:50:56 abs Exp $

BUILDLINK_TREE+=	iodbc

.if !defined(IODBC_BUILDLINK3_MK)
IODBC_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.iodbc+=	iodbc>=3.52.3
BUILDLINK_INCDIRS.iodbc?=	${PREFIX}/include
BUILDLINK_LIBDIRS.iodbc?=	${PREFIX}/lib
BUILDLINK_PKGSRCDIR.iodbc?=	../../databases/iodbc

# ODBC drivers don't need these bits, but ODBC clients do.
.if !defined(ODBC_DRIVER)
.  include "../../mk/dlopen.buildlink3.mk"
.  include "../../mk/pthread.buildlink3.mk"
.endif
.endif # IODBC_BUILDLINK3_MK

BUILDLINK_TREE+=	-iodbc
