# $NetBSD: buildlink3.mk,v 1.2 2004/01/04 23:34:05 jlam Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
DB2_BUILDLINK3_MK:=	${DB2_BUILDLINK3_MK}+

.if !empty(DB2_BUILDLINK3_MK:M+)
BUILDLINK_PACKAGES+=		db
BUILDLINK_DEPENDS.db?=		db>=2.7.3
BUILDLINK_PKGSRCDIR.db?=	../../databases/db
.endif	# DB2_BUILDLINK3_MK

.if !defined(_NEED_DB2)
_NEED_DB2=	YES
.  if defined(USE_DB185)
.    if exists(/usr/include/db.h)	# NetBSD, Darwin
BUILDLINK_PREFIX.db=	/usr
_NEED_DB2=	NO
.    elif exists(/usr/include/db1/db.h)	# Linux
BUILDLINK_PREFIX.db=	/usr
BUILDLINK_INCDIRS.db=	include/db1
BUILDLINK_TRANSFORM+=	l:db:db1
_NEED_DB2=	NO
.    endif
.  endif
MAKEFLAGS+=	_NEED_DB2="${_NEED_DB2}"
.endif

.if ${_NEED_DB2} == "YES"
.  if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	db
.  endif
.endif

.if !empty(DB2_BUILDLINK3_MK:M+)
.  if ${_NEED_DB2} == "YES"
BUILDLINK_INCDIRS.db=	include/db2
BUILDLINK_TRANSFORM+=	l:db:db2
.  endif
.endif	# DB2_BUILDLINK3_MK

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:C/\+$//}
